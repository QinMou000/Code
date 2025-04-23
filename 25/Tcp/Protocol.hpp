#pragma once
#include "Common.hpp"
#include <jsoncpp/json/json.h>

using namespace LogModule;

class Request
{
public:
    std::string Serialize()
    {
        Json::Value root;
        root["x"] = _x;
        root["y"] = _y;
        root["oper"] = _oper;
        Json::FastWriter writer;
        std::string s = writer.write(root);
        return s;
    }
    // {"oper":43,"x":10,"y":20}
    bool Deserialize(std::string mesg)
    {
        Json::Value root;
        Json::Reader reader;

        if (!reader.parse(mesg, root))
        {
            LOG(LogLevel::ERROR) << "反序列化失败: " << mesg;
            return false;
        }
        _x = root["x"].asInt();
        _y = root["y"].asInt();
        _oper = root["oper"].asInt(); // 就把操作符看作ascall码值
        return true;
    }
    int X()
    {
        return _x;
    }
    int Y()
    {
        return _y;
    }
    char Oper()
    {
        return _oper;
    }

private:
    float _x;
    float _y;
    char _oper;
};

class Response
{
public:
    Response() {}
    Response(int res, int code)
        : _res(res),
          _code(code)
    {
    }
    std::string Serialize()
    {
        Json::Value root;
        root["res"] = _res;
        root["code"] = _code;
        Json::FastWriter writer;
        return writer.write(root);
    }
    // {"res":10,"code":0}
    bool Deserialize(std::string mesg)
    {
        Json::Value root;
        Json::Reader reader;

        if (!reader.parse(mesg, root))
        {
            LOG(LogLevel::ERROR) << "反序列化失败: " << mesg;
            return false;
        }
        _res = root["res"].asInt();
        _code = root["code"].asInt();
        return true;
    }
    void SetRes(int res)
    {
        _res = res;
    }
    void SetCode(int code)
    {
        _code = code;
    }

private:
    float _res;
    int _code; // 0表示结果可信
};

const std::string sep = "\r\n";

using cal_t = std::function<Response(Request&)>;

class Protocol
{
public:
    Protocol(cal_t cal)
        : _cal(cal)
    {
    }
    // 添加报头  {"oper":43,"x":10,"y":20}  ---->  size\r\n{"oper":43,"x":10,"y":20}\r\n
    std::string Encode(std::string &json_str)
    {
        return std::to_string(json_str.size()) + sep + json_str + sep; // 报文长度+分隔符+报文+分隔符
    }
    // 5
    // 50
    // 50\r
    // 50\r\n
    // 50\r\n{"x": 10, "
    // 50\r\n{"x": 10, "y" : 20, "oper" : '+'}\r\n
    // 50\r\n{"x": 10, "y" : 20, "oper" : '+'}\r\n50\r\n{"x": 10, "y" : 20, "ope

    // 提取报文  size\r\n{"oper":43,"x":10,"y":20}\r\n  ---->  {"oper":43,"x":10,"y":20}
    bool Decode(std::string &buffer, std::string &json)
    {
        ssize_t pos = buffer.find(sep);
        if (pos == std::string::npos)
        {
            LOG(LogLevel::ERROR) << "Decode err";
            return false;
        }
        std::string len_str = buffer.substr(0, pos); // 提取表示报文长度的字符串
        int len = std::stoi(len_str);                // 将字符串转化为整数

        int target_len = len_str.size() + len + 2 * sep.size(); // 提取报文成功后，要删除的报文长度

        buffer.erase(0, target_len);                 // 删除已经被提取的报文
        json = buffer.substr(pos + sep.size(), len); // 要返回的结果
        return true;
    }
    void GetRequest(std::shared_ptr<Socket> &sock, InetAddr &client)
    {
        std::string buffer_queue;
        while (1)
        {
            std::string req_json;
            int n = sock->Recv(&buffer_queue);
            if (n > 0)
            {
                while (Decode(buffer_queue, req_json))
                {
                    Request req;
                    Response res;
                    bool ok = req.Deserialize(req_json); // 将提取的的请求报文反序列化
                    if (!ok)
                        continue;
                    res = _cal(req);                              // 又传给上一层计算器处理
                    std::string res_json = res.Serialize();       // 将上一层返回的res序列化
                    std::string send_res_json = Encode(res_json); // 添加报头
                    sock->Send(send_res_json);                    // 将最终结果报文发给客户端
                }
            }
            else if (n == 0)
            {
                // 读不到东西，说明客户端退了
                LOG(LogLevel::INFO) << "client " << client.StringAddr() << " quit!";
                break;
            }
            else
            {
                // 读取错误
                LOG(LogLevel::INFO) << "client " << client.StringAddr() << " recv error";
                break;
            }
        }
    }

private:
    cal_t _cal;
};
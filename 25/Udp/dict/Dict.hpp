#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "log.hpp"

using namespace LogModule;

std::string DictPath = "./dictionary.txt";
const std::string sep = ": ";

class Dict
{
public:
    Dict(std::string dictpath = DictPath)
        : _dict_path(dictpath)
    {
    }
    bool LoadWords()
    {
        std::ifstream in(_dict_path);
        if (!in.is_open())
        {
            LOG(LogLevel::ERROR) << "打开字典文件" << _dict_path << "错误";
            return false;
        }
        std::string line;
        while (std::getline(in, line))
        {
            size_t pos = line.find(sep);
            if (pos == std::string::npos)
            {
                LOG(LogLevel::WARNING) << "解析失败" << line;
                continue;
            }

            std::string en = line.substr(0, pos);
            std::string ch = line.substr(pos + sep.size());

            if (en.empty() || ch.empty())
            {
                LOG(LogLevel::WARNING) << "无有效内容" << line;
                continue;
            }

            _dict.insert(std::make_pair(en, ch));
            LOG(LogLevel::INFO) << "载入成功";
        }
        in.close();
        return true;
    }
    std::string Translate(const std::string word)
    {
        auto iter = _dict.find(word);
        if (iter == _dict.end())
        {
            LOG(LogLevel::ERROR) << "not find this word in dictionary";
            return "None";
        }
        // 返回迭代器的第二个
        LOG(LogLevel::DEBUG) << "find successing";
        return iter->second;
    }
    ~Dict()
    {
    }

private:
    std::unordered_map<std::string, std::string> _dict;
    std::string _dict_path;
};
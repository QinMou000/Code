#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "log.hpp"

using namespace LogModule;

std::string DictPath = "./dictionary";
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
        while(std::getline(in, line))
        {
            size_t pos = find(sep);
            if(pos == std::string::npos)
            {
                LOG(LogLevel::WARNING) << "解析失败" << line;
                continue;
            }
            
            std::string en = line.substr(0, pos);
            std::string ch = line.substr(pos + sep, line.size());

        }
        return true

    }
    std::string Translate(std::string word)
    {
        auto iter = _dict.find(word) if (iter == _dict.end())
        {
            LOG(LogLevel::ERROR) << "not find this word in dictionary";
            return "None";
        }
        // 返回迭代器的第二个
        LOG(LogLevel::DEBUG) << "find successing";
        return iter.second;
    }
    ~Dict()
    {
    }

private:
    std::unordered_map<std::string, std::string> _dict;
    std::string _dict_path
};
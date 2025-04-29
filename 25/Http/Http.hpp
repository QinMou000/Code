#pragma once
#include "Common.hpp"
#include <unordered_map>

const std::string line_break = "\r\n"; // 换行符
const std::string blank = " ";         // 空格

class Request
{
public:
    Request() {}
    ~Request() {}

private:
    std::string _method;       // 请求方法
    std::string _uri;          // URI 请求资源路径
    std::string _http_version; // http版本

    unordered_map<std::string, std::string> _headers; // 请求报头

    std::string _text // 请求正文
};

class Response
{
public:
    Response() {}

    ~Response() {}

private:
    std::string _http_version; // http版本
    int _code;                 // 状态码
    std::string desc;          // 状态码描述

    unordered_map<std::string, std::string> _headers; // 响应报头

    std::string _text // 响应正文
};

class Http
{
public:
    Http() {}
    ~Http() {}

private:
};
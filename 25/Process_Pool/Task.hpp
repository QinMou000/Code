#pragma once

#include <iostream>
#include <vector>

typedef void (*task)();

void printlog()
{
    std::cout << "打印日志" << std::endl;
}

void upload()
{
    std::cout << "上传任务" << std::endl;
}

void download()
{
    std::cout << "下载任务" << std::endl;
}

class Task
{
public:
    Task()
    {
        srand(time(nullptr));
    }
    void Register(task t)
    {
        _t.emplace_back(t);
    }
    void Excutive(int code)
    {
        if (code < _t.size() && code >= 0)
        {
            _t[code]();
        }
        else
            std::cout << "任务码错误" << std::endl;
    }
    int Select_Task() // 随机选择任务
    {
        int code = rand() % _t.size();
        std::cout << "选择的任务码为:" << code << std::endl;
        return code;
    }
    ~Task()
    {
    }

private:
    std::vector<task> _t; // 用数组管理任务，顺便将下标作为任务码code
};
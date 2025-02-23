#ifndef __PROCESS_POOL_HPP__
#define __PROCESS_POOL_HPP__

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "Task.hpp"

class channel
{
public:
    channel(pid_t id, int fd)
        : _subid(id),
          _wfd(fd)
    {
        _name = "channel-" + std::to_string(_wfd) + "-" + std::to_string(_subid);
    }
    void Send(int code)
    {
        int n = write(_wfd, &code, sizeof(code));
        if (n < 0)
        {
            std::cout << "写入任务码失败" << std::endl;
        }
    }
    void Close()
    {
        close(_wfd);
        std::cout << "关闭信道：" << Name() << std::endl;
    }
    void Wait_Pid()
    {
        pid_t rid = waitpid(_subid, nullptr, 0);
        std::cout << "等待信道" << Name() << std::endl;
        if (rid < 0)
        {
            std::cout << "等待失败" << std::endl;
        }
    }
    std::string Name()
    {
        return _name;
    }
    ~channel() {}

private:
    pid_t _subid;      // child_pid
    int _wfd;          // 父进程要往哪里写东西(文件描述符,pipe的写端)
    std::string _name; // 信道名
};

class channel_manager
{
public:
    channel_manager()
        : _next(0)
    {
    }
    void insert(pid_t subid, int fd)
    {
        _c.emplace_back(subid, fd); // ###########################################################################
    }
    channel &Select_Channel() // 轮询选择信道
    {
        channel &c = _c[_next];
        _next++;
        _next %= _c.size();
        std::cout << "选择的信道是:" << c.Name() << std::endl;
        return c;
    }
    void Close_Channel()
    {
        for (auto &Channel : _c)
        {
            Channel.Close();
            sleep(1);
        }
    }
    void Wait()
    {
        for (auto &Channel : _c)
        {
            Channel.Wait_Pid();
            sleep(1);
        }
    }
    void Close_And_Wait() 
    {
        for (auto &channel : _c)
        {
            channel.Close();
            channel.Wait_Pid();
        }
        // for (int i = _c.size() - 1; i >= 0; i--) // 第一种方案：从后往前关，详情请观看Linux 2025-2-20进程IPC 1:36:20
        // {
        //     _c[i].Close();
        //     _c[i].Wait_Pid();
        // }
    }
    void print_channel()
    {
        for (auto &e : _c)
            std::cout << e.Name() << std::endl;
    }
    ~channel_manager() {}

private:
    std::vector<channel> _c; // 用一个数组管理每一个信道
    int _next;               // 表示下一个调用的信道在数组中的下标
};

const int default_num = 5; // 默认开5个信道

class process_pool
{
public:
    process_pool()
        : _channel_num(default_num)
    {
        _task.Register(printlog); // 将任务都注册到_task里面
        _task.Register(upload);
        _task.Register(download);
    }
    void Work(int rfd)
    {
        while (1)
        {
            int code = 0;
            ssize_t n = read(rfd, &code, sizeof(code));
            if (n > 0)
            {
                if (n != sizeof(code))
                    continue;
                std::cout << "子进程pid:" << getpid() << "收到一个任务码：" << code << std::endl;
                _task.Excutive(code);
            }
            else if (n == 0)
            {
                std::cout << "子进程退出" << std::endl;
                break;
            }
            else
            {
                std::cout << "读取错误" << std::endl;
                break;
            }
        }
    }
    void Start()
    {
        for (int i = 0; i < _channel_num; i++)
        {
            int pipefd[2] = {0};
            int n = pipe(pipefd);
            if (n < 0)
            {
                std::cout << "信道开启失败" << std::endl;
                exit(1);
            }

            pid_t subid = fork(); // 创建子进程
            if (subid < 0)
            {
                std::cout << "子进程创建失败" << std::endl;
            }
            if (subid == 0) // 子进程
            {
                // 1.关闭写端
                close(pipefd[1]);
                // 第二种方案：关闭从父进程那你继承来的，哥哥进程的写端 详情请观看Linux 2025-2-20进程IPC 1:36:20
                _cm.Close_Channel();
                // 2.开始工作，准备读取父进程发送的信息
                Work(pipefd[0]);
                // 3.关闭读端，并退出进程
                close(pipefd[0]);
                exit(0);
            }
            else // 父进程
            {
                // 1.关闭读端
                close(pipefd[0]);
                // 2.将信道信息插入manager方便管理
                _cm.insert(subid, pipefd[1]);
            }
        }
    }
    void Run()
    {
        // 选择任务
        int code = _task.Select_Task();
        // 选择信道
        channel &ch = _cm.Select_Channel();
        // 往信道里面写code
        ch.Send(code);
    }
    void Stop()
    {
        // _cm.Close_Channel(); // 关闭所有父进程的wfd，子进程读到0自动退出
        // _cm.Wait();          // 回收所有子进程

        _cm.Close_And_Wait();
    }
    void Debug()
    {
        _cm.print_channel();
    }
    ~process_pool() {}

private:
    channel_manager _cm; // 进程池通过调用_cm的方法，管理信道
    int _channel_num;    // 信道个数
    Task _task;
};
#endif
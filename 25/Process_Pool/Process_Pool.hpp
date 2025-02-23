#program once

#include <iostream>
#include <vector>
#include <unistd.h>

class channel
{
public:
    channel(int fd, pid_t id)
        : _wfd(fd),
          _cid(id)
    {
        _name = "channel-" + to_string(_wfd) + to_string(cid);
    }
    ~channel() {}

private:
    int _wfd;              // 父进程要往哪里写东西(文件描述符,pipe的写端)
    pid_t _cid               // child_pid
    std::string _name;     // 信道名
}

class channel_manager
{
public:
    channel_manager() {}
    ~channel_manager() {}

private:
    vector<channel> _c; // 用一个数组管理每一个信道
}

class process_pool
{
public:
    process_pool() {}
    ~process_pool() {}

private:
    channel_manager _cm; // 进程池通过调用_cm的方法，管理信道
}

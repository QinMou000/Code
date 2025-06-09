#pragma once
#include <sys/epoll.h>

class Epoller // epoll模型
{
public:
    Epoller() {}
    ~Epoller() {}

private:
    int _epfd;
};

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>

class Thread
{
private:
public:
    Thread()
        : _tid(0)
    {
    }
    bool Start()
    {
    }
    bool Detach()
    {
    }
    bool Join()
    {
    }
    ~Thread()
    {
    }

private:
    pthread_t _tid;
    std::string _name;
};
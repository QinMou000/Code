#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <functional>

using func_t = std::function<void()>;

class Thread
{
private:
    static void *routine(void *args)
    {
        Thread *self = static_cast<Thread *>(args);
        self->_func();
        return nullptr;
    }

public:
    Thread(func_t func)
        : _tid(0),
          _func(func),
          _is_detach(false)
    {
    }
    bool Start()
    {
        if (_tid == 0)
        {
            pthread_create(&_tid, nullptr, routine, this);
            if (_is_detach = true)
                pthread_detach(_tid);

            return true;
        }
        return false;
    }
    bool Detach()
    {
        if (_tid != 0)
        {
            pthread_detach(_tid);
            return true;
        }
        else
            _is_detach = true;

        return false;
    }
    bool Join()
    {
        if (_tid != 0)
        {
            pthread_join(_tid, nullptr);
            return true;
        }
        return false;
    }
    ~Thread()
    {
    }

private:
    pthread_t _tid;
    func_t _func;
    bool _is_detach;
};
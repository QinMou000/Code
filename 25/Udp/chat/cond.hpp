#pragma once
#include <iostream>
#include <pthread.h>
#include "mutex.hpp"

class Cond
{
public:
    Cond()
    {
        pthread_cond_init(&_cond, nullptr);
    }
    void Wait(Mutex mutex)
    {
        pthread_cond_wait(&_cond, mutex.Get());
    }
    void Signal()
    {
        pthread_cond_signal(&_cond);
    }
    void Broadcast()
    {
        // 唤醒所有在条件变量下等待的线程
        int n = pthread_cond_broadcast(&_cond);
    }
    ~Cond()
    {
        pthread_cond_destroy(&_cond);
    }

private:
    pthread_cond_t _cond;
};

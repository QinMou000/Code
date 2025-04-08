#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "log.hpp"
#include "thread.hpp"
#include "cond.hpp"

using namespace LogModule;

const int defaultnum = 5;

template <class T>
class ThreadPool // 进程池
{
private:
    void WakeOne()
    {
        LOG(LogLevel::INFO) << "唤醒一个线程";
        _cond.Signal();
    }
    void WakeAll()
    {
        if (_sleep_num)
        {
            _cond.Broadcast();
            LOG(LogLevel::INFO) << "唤醒所有线程";
        }
    }

public:
    ThreadPool(int num = defaultnum)
        : _num(num),
          _is_running(false),
          _sleep_num(0)
    {
        for (int i = 0; i < _num; i++)
        {
            LOG(LogLevel::INFO) << "线程创建";
            _thread_queue.emplace_back(
                [this] /*捕获列表*/ ()
                {
                    Handler(); // 将handler函数传入线程中初始化
                });
        }
    }
    void Start()
    {
        if (_is_running)
            return;
        _is_running = true;
        for (auto &thread : _thread_queue)
        {
            LOG(LogLevel::INFO) << "线程启动";
            thread.Start();
        }
    }
    void Handler()
    {
        T t; // 任务
        LOG(LogLevel::INFO) << "_is_running:" << _is_running;
        while (true)
        {
            {
                global_mutex glock(_mutex);                // 一次只有一个线程进入临界区拿任务
                while (_task_queue.empty() && _is_running) // 如果任务队列为空，并且进程池没有退出，那就在条件变量下等
                {
                    LOG(LogLevel::INFO) << "线程等待_is_running:" << _is_running;
                    _sleep_num++;
                    _cond.Wait(_mutex);
                    _sleep_num--;
                }
                if (_task_queue.empty() && !_is_running)
                {
                    LOG(LogLevel::INFO) << "退出了, 线程池退出&&任务队列为空";
                    break;
                }
                // 有任务才会被唤醒
                t = _task_queue.front();
                _task_queue.pop(); // 弹出任务
            }
            t(); // 执行任务
        }
    }
    void Stop()
    {
        if (!_is_running)
            return;
        _is_running = false;
    }
    void Equeue(T in) // 往任务队列里面压任务，唤醒线程
    {
        if (!_is_running)
            return;
        {
            global_mutex glock(_mutex); // 一次只有一个线程进入临界区压入任务
            _task_queue.push(in);
            if (_sleep_num > 0)
                WakeOne();
        }
    }
    ~ThreadPool()
    {
    }

private:
    std::vector<Thread> _thread_queue; // 线程队列
    int _num;                          // 线程池中线程个数
    std::queue<T> _task_queue;         // 任务队列
    Mutex _mutex;                      // 维持线程间拿取任务的互斥关系
    Cond _cond;                        // 当任务队列为空时，可以在条件变量下等待
    bool _is_running;                  // 标识进程池是否在运行
    int _sleep_num;                    // 标识正在休眠的线程个数
};
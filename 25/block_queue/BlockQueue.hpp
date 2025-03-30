#pragma once
#include "cond.hpp"
#include "mutex.hpp"
#include "thread.hpp"
#include <queue>
#include <iostream>

const int defaultnum = 10; // 默认队列长度

template <class T>
class BlockQueue
{
private:
    bool IsFull()
    {
        return _q.size() == _cap;
    }
    bool IsEmpty()
    {
        return _q.empty();
    }

public:
    BlockQueue(int cap = defaultnum)
        : _cap(cap),
          _psleep(0),
          _csleep(0)
    {
    }
    void Equeue(const T &in) // 生产者调用，往队列里面生产东西
    {
        {
            global_mutex gmutex(_mutex);
            while (IsFull()) // 如果队列里为满，那就让线程一直在条件变量下等待
            {
                _psleep++;
                std::cout << "生产者进入等待" << std::endl;
                Pcond.Wait(_mutex);
                _psleep--;
            }
            // 队列有空位置
            _q.push(in);
            std::cout << "入队列" << std::endl;
            if (_csleep > 0) // 通知消费者来消费
            {
                std::cout << "通知消费者来消费" << std::endl;
                Ccond.Signal();
            }
        }
    }
    T Pop() // 消费者调用
    {
        T out;
        {
            global_mutex gmutex(_mutex); // 利用类内的锁创建可以自动解锁的锁
            while (IsEmpty())            // 如果队列里为空，那就让线程一直在条件变量下等待
            {
                _csleep++;
                std::cout << "消费者进入等待" << std::endl;
                Ccond.Wait(_mutex);
                _csleep--;
            }
            out = _q.front();
            _q.pop();
            std::cout << "出队列" << std::endl;

            if (_psleep > 0) // 通知生产者去生产
            {
                std::cout << "通知生产者去生产" << std::endl;
                Pcond.Signal();
            }
        }
        return out;
    }
    ~BlockQueue()
    {
    }

private:
    std::queue<T> _q; // 可以用vector代替，都看心情~
    int _cap;         // 队列容量

    Mutex _mutex; // 为了维护p与c，p与p，c与c之间的互斥关系
    Cond Pcond;   // 维护p与p之间的同步
    Cond Ccond;   // 维护c与c之间的同步

    int _psleep; // 生产者休眠数
    int _csleep; // 消费者休眠数
};
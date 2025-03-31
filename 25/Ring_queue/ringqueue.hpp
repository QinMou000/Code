#pragma once
#include "sem.hpp"
#include "mutex.hpp"
#include <vector>
#include <iostream>

const int default_len = 5; // 默认循环队列长度

template <class T>
class RingQueue
{
public:
    RingQueue(int len = default_len)
        : _rq(len),
          _cap(len),
          _c_step(0),
          _data_sem(0),
          _p_step(0),
          _blank_sem(_cap)
    {
    }
    void Equeue(T &in) // 生产者调用
    {
        _blank_sem.P(); // 申请资源
        {
            global_mutex glock(_p_lock); // 可以先让一批线程竞争信号量，再来竞争锁，后来的线程，就挂在信号量上
            _rq[_p_step] = in;
            _p_step++;
            _p_step %= _cap;
        }
        _data_sem.V(); // 对消费者资源++；
    }
    T Pop() // 消费者调用
    {
        T data;
        _data_sem.P(); // 申请资源
        {
            global_mutex glock(_c_lock);
            data = _rq[_c_step];
            _c_step++;
            _c_step %= _cap;
        }
        _blank_sem.V(); // 对生产者资源++
        return data;
    }
    ~RingQueue()
    {
    }

private:
    std::vector<T> _rq; // 用vector来模拟循环队列
    int _cap;           // 标记长度，用来模等，维持循环属性

    int _c_step;   // 消费者位置
    Sem _data_sem; // 记录对于消费者来说的资源，也就是有数据的位置数

    int _p_step;    // 生产者位置
    Sem _blank_sem; // 记录对于生产者来说的资源，也就是空位置数

    // 为了支持多生产多消费，需要再加两把锁维持p与p，v与v之间的互斥关系
    Mutex _c_lock;
    Mutex _p_lock;
};

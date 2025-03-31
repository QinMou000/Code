#pragma once

#include <semaphore.h>

const int defalut = 1;
class Sem
{
public:
    Sem(unsigned int sem_value = defalut)
    {
        sem_init(&_sem, 0, sem_value); // 第二个参数为零则在线程间共享，第三个参数指定信号量的初始值
    }
    void P() // P(Proberen)操作 对信号量计数器--,申请资源
    {
        sem_wait(&_sem); // 本身是原子的
    }
    void V() // V(Verhogen)操作 对信号量计数器++，释放资源
    {
        sem_post(&_sem); // 本身是原子的
    }
    ~Sem()
    {
        sem_destroy(&_sem);
    }
private:
    sem_t _sem;
};
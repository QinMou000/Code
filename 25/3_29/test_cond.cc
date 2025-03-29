#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>

struct thread
{
    pthread_t tid;
    std::string name;
};

pthread_mutex_t gmutex = PTHREAD_MUTEX_INITIALIZER; // 定义全局锁
pthread_cond_t gcond = PTHREAD_COND_INITIALIZER;    // 定义全局条件变量

void *routine(void *args)
{
    while (true)
    {
        pthread_mutex_lock(&gmutex);
        pthread_cond_wait(&gcond, &gmutex); // 一个线程先拿到了锁，但是它要在条件变量下等，
                                            // 就要先把锁释放掉，让给其他线程, 当这个线程被唤醒时
                                            // 先去申请锁，然后也是从这个函数开始执行。

        std::cout << "完成任务..." << std::endl;

        pthread_mutex_unlock(&gmutex);
    }
    return nullptr;
}

int main()
{
    std::vector<thread> threads;
    for (int i = 0; i < 5; i++)
    {
        thread t;
        t.name = "thread-" + i;
        pthread_create(&t.tid, nullptr, routine, nullptr);
        threads.push_back(t);
        sleep(1);
    }

    while (true)
    {
        pthread_cond_signal(&gcond);
        std::cout << "唤醒一个线程" << std::endl;
        sleep(1);
    }

    for (auto &e : threads)
    {
        pthread_join(e.tid, nullptr);
    }

    return 0;
}
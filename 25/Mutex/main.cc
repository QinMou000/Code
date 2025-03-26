#include "mutex.hpp"
#include <pthread.h>
#include <unistd.h>

int ticket = 10000;

void *routine(void *args)
{
    Mutex *m = static_cast<Mutex *>(args);
    while (true)
    {
        // m->Lock();
        if (ticket > 0)
        {
            usleep(100);
            std::cout << "抢票一次" << std::endl;
            ticket--;
            std::cout << "剩余票数：" << ticket << std::endl;
            // m->UnLock();
        }
        else
        {
            // m->UnLock();
            break;
        }
    }
    return nullptr;
}

int main()
{
    Mutex mutex;

    pthread_t t1;
    pthread_create(&t1, nullptr, routine, (void *)&mutex);
    pthread_t t2;
    pthread_create(&t2, nullptr, routine, (void *)&mutex);
    pthread_t t3;
    pthread_create(&t3, nullptr, routine, (void *)&mutex);
    pthread_t t4;
    pthread_create(&t4, nullptr, routine, (void *)&mutex);

    while (true)
    {
        pthread_join(t1, nullptr);
        pthread_join(t2, nullptr);
        pthread_join(t3, nullptr);
        pthread_join(t4, nullptr);
    }

    return 0;
}
#include "sem.hpp"
#include "ringqueue.hpp"
#include <unistd.h>
#include <pthread.h>

int cnt = 1;

void *product(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);
    while (true)
    {
        std::cout << "product" << cnt << std::endl;
        rq->Equeue(cnt);
        cnt++;
        // sleep(1);
    }
}

void *comsumer(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);
    while (true)
    {
        int ans = rq->Pop();
        std::cout << "comsumer" << ans << std::endl;

        sleep(1);
    }
}

int main()
{
    RingQueue<int> rq;

    pthread_t tid1;
    pthread_create(&tid1, nullptr, product, &rq);
    pthread_t tid2;
    pthread_create(&tid2, nullptr, product, &rq);

    pthread_t tid3;
    pthread_create(&tid3, nullptr, comsumer, &rq);
    pthread_t tid4;
    pthread_create(&tid4, nullptr, comsumer, &rq);
    pthread_t tid5;
    pthread_create(&tid5, nullptr, comsumer, &rq);

    while (1)
    {
    }
    return 0;
}
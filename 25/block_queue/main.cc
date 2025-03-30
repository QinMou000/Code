#include "BlockQueue.hpp"

void *product(void *args)
{
    BlockQueue<int> *bq = static_cast<BlockQueue<int> *>(args);
    int n = 0;
    while (true)
    {
        n++;
        bq->Equeue(n);
        // sleep(2);
        std::cout << "product:" << n << std::endl;
    }
}
void *comsumer(void *args)
{

    BlockQueue<int> *bq = static_cast<BlockQueue<int> *>(args);
    while (true)
    {
        int n = bq->Pop();
        std::cout << "comsumer:" << n << std::endl;
        // sleep(1);
    }
}

int main()
{
    BlockQueue<int> bq;
    pthread_t tid1;
    pthread_create(&tid1, nullptr, product, &bq);

    pthread_t tid2;
    pthread_create(&tid2, nullptr, comsumer, &bq);

    while (true)
    {
    }
    return 0;
}
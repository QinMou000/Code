#include "mutex.hpp"
#include <pthread.h>

int ticket = 1000;

void *routine1(void *args)
{

}

void *routine2(void *args)
{

}

int main()
{
    pthread_t t1;
    pthread_create(&t1, nullptr, routine1, nullptr);
    pthread_t t2;
    pthread_create(&t1, nullptr, routine2, nullptr);
    return 0;
}
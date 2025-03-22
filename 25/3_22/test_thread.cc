#include <iostream>
#include <unistd.h>
#include <pthread.h>

void *routine(void *argc)
{
    int cnt = 3;
    while (cnt--)
    {
        sleep(1);
        std::cout << "i am a new thread" << std::endl;
    }

    int *ret = (int *)malloc(sizeof(int));
    ret = (int *)10;
    return (void *)ret;
}

int main()
{
    pthread_t t;
    pthread_create(&t, nullptr, routine, nullptr);
    printf("tid : 0x%lx\n", t);
    // std::cout << "tid:" << t << std::endl;
    int cnt = 5;
    while (cnt--)
    {
        sleep(1);
        std::cout << "i am main thread" << std::endl;
    }

    int *ret = (int *)malloc(sizeof(int));
    pthread_join(t, (void **)&ret);
    printf("ret : %d\n", ret);
    std::cout << ret << std::endl;
    return 0;
}
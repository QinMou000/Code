// #include "thread.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
void *threadrun(void *args)
{
    int cnt = 5;
    while (cnt--)
    {
        std::cout << "i am a new thread" << std::endl;
        sleep(1);
    }
    int ret = 10;
    return (void *)ret;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, threadrun, nullptr);
    int *ans;
    pthread_join(tid, (void **)&ans);
    std::cout << ans << std::endl;
    return 0;
}
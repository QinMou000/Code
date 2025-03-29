#include "cond.hpp"
#include "thread.hpp"

Cond cond;

void routine()
{
    Mutex lock;
    lock.Lock();
    std::cout << "线程等待..." << std::endl;
    cond.Wait(lock);
    std::cout << "完成任务..." << std::endl;
    lock.UnLock();
    return;
}

int main()
{
    std::string name("thread-1");
    Thread thread(name, routine);
    thread.Start();
    std::cout << "线程开始执行..." << std::endl;

    sleep(3);

    cond.Signal();

    std::cout << "线程被唤醒..." << std::endl;

    sleep(3);

    thread.Join();
    return 0;
}
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/syscall.h>

void handler(int signo)
{
    std::cout << "pid:" << getpid() << std::endl;
    std::cout << "signo:" << signo << std::endl;
}

void PrintPending(sigset_t &pending)
{
    std::cout << "pid:" << getpid() << ",sigo:";
    for (int signo = 31; signo >= 1; signo--)
        if (sigismember(&pending, signo))
            std::cout << 1;
        else
            std::cout << 0;
    std::cout << std::endl;
}

int main()
{
    signal(SIGALRM, handler);
    alarm(1);
    while(1){
        ;
    }
    return 0;
}

// int main()
// {
//     // for (int i = 1; i <= 31; i++)
//     // {
//     //     signal(i, handler);
//     // }

//     // signal(2, handler);

//     sigset_t block_set, old_set;
//     sigemptyset(&block_set);
//     sigemptyset(&old_set);
//     sigaddset(&block_set, SIGINT); // 屏蔽SIGNINT信号，但还没有设置到内核中

//     sigprocmask(SIG_BLOCK, &block_set, &old_set); // 设置到内核中

//     int cnt = 10;
//     while (1)
//     {
//         sigset_t pending;
//         sigpending(&pending);

//         PrintPending(pending);
//         cnt--;
//         if (cnt == 0)
//         {
//             std::cout << "解除对二号SIG_BLOCK信号的屏蔽" << std::endl;
//             sigprocmask(SIG_SETMASK, &old_set, &block_set);
//         }
//         sleep(1);
//     }
//     return 0;
// }
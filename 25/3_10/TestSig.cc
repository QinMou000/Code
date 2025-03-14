#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/syscall.h>
#include <sys/wait.h>

void WaitAll(int num)
{
    while (true)
    {
        pid_t n = waitpid(-1, nullptr, WNOHANG); // 阻塞了！
        if (n == 0)
        {
            break;
        }
        else if (n < 0)
        {
            std::cout << "waitpid error " << std::endl;
            break;
        }
    }
    std::cout << "father get a signal: " << num << std::endl;
}

int main()
{
    signal(SIGCHLD, WaitAll); // 父进程
    for (int i = 0; i < 10; i++)
    {
        pid_t id = fork(); // 如果我们有10个子进程呢？？6退出了，4个没退
        if (id == 0)
        {
            sleep(3);
            std::cout << "I am child, exit" << std::endl;
            exit(3);
            // if(i <= 6) exit(3);
            // else pause();
        }
    }

    while (true)
    {
        std::cout << "I am fater, exit" << std::endl;
        sleep(1);
    }

    return 0;
}

//
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
#include <iostream>
#include <vector>
#include <functional>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{   
    sigset_t set, oset;
    sigemptyset(&set);
    sigemptyset(&oset);

    

    return 0;
}

// struct task_struct
// {
//     ...
//         /* signal handlers */
//         struct sighand_struct *sighand;
//     sigset_t blocked struct sigpending pending;
//     ...

// }

// struct sighand_struct
// {
//     atomic_t count;
//     struct k_sigaction action[_NSIG]; // #define _NSIG 64
//     spinlock_t siglock;
// };

// struct __new_sigaction
// {
//     __sighandler_t sa_handler;
//     unsigned long sa_flags;
//     void (*sa_restorer)(void); /* Not used by Linux/SPARC */
//     __new_sigset_t sa_mask;
// };

// struct k_sigaction
// {
//     struct __new_sigaction sa;
//     void __user *ka_restorer;
// };

// /* Type of a signal handler. */
// typedef void (*__sighandler_t)(int);
// struct sigpending
// {
//     struct list_head list;
//     sigset_t signal;
// };

// struct task_struct
// {
//     ...
//         /* signal handlers */
//         struct sighand_struct *sighand;
//     sigset_t blocked struct sigpending pending;
//     ...

// }

// struct sighand_struct
// {
//     atomic_t count;
//     struct k_sigaction action[_NSIG]; // #define _NSIG 64
//     spinlock_t siglock;
// };

// struct __new_sigaction
// {
//     __sighandler_t sa_handler;
//     unsigned long sa_flags;
//     void (*sa_restorer)(void); /* Not used by Linux/SPARC */
//     __new_sigset_t sa_mask;
// };

// struct k_sigaction
// {
//     struct __new_sigaction sa;
//     void __user *ka_restorer;
// };

// /* Type of a signal handler. */
// typedef void (*__sighandler_t)(int);
// struct sigpending
// {
//     struct list_head list;
//     sigset_t signal;
// };

using func_t = std::function<void()>;
std::vector<func_t> task;

void handler(int signo)
{
    for (auto f : task)
    {
        f();
    }
    int n = alarm(1);
    std::cout << "n: " << n << std::endl;
}

int main()
{
    task.push_back([]()
                   { std::cout << "刷新内核" << std::endl; });
    task.push_back([]()
                   { std::cout << "检测进程时间片" << std::endl; });
    task.push_back([]()
                   { std::cout << "管理内存" << std::endl; });

    signal(SIGALRM, handler);

    alarm(1);

    while (true)
    {
        pause();
        std::cout << "wake up" << std::endl;
    }
    return 0;
}

// int cnt = 0;

// void Exit(int signo)
// {
//     std::cout << cnt << std::endl;
//     exit(1);
// }

// int main()
// {
//     signal(SIGALRM, Exit);
//     alarm(1);

//     while (true)
//     {
//         std::cout << "cnt:" << cnt << std::endl;
//         cnt++;
//     }
//     return 0;
// }

// // mykill -signumber pid
// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//     {
//         std::cerr << "Usage: " << argv[0] << " -signumber pid" << std::endl;
//         return 1;
//     }
//     int number = std::stoi(argv[1] + 1); // 去掉- 获取信号编号
//     pid_t pid = std::stoi(argv[2]);
//     int n = kill(pid, number);
//     return n;
// }

// void handler(int signumber)
// {
//     std::cout << "我是: " << getpid() << ", 我获得了⼀个信号: " << signumber << std::endl;
// }

// int main()
// {
//     std::cout << "我是进程: " << getpid() << std::endl;
//     signal(SIGINT /*2*/, handler); // 设置自定义函数处理
//     while (true)
//     {
//         std::cout << "I am a process, I am waiting signal!" << std::endl;
//         sleep(1);
//     }
//     return 0;
// }

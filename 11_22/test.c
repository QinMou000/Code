// #include<stdio.h>
// #include<unistd.h>

// int main()
// {
//     while(1)
//     {
//         printf("我是一个进程pid:%d,ppid:%d\n",getpid(),getppid());
//         sleep(1);
//     }
//     return 0;
// }
// #include<stdio.h>
// #include<unistd.h>
// int main()
// {
//   printf("I am running\n");
//   sleep(100);
//   return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    pid_t id = fork();
    if (id == 0) 
    {
        // child
        int count = 3;
        while (count > 0) {
            printf("我是子进程 pid:%d,ppid: %d\n", getpid(), getppid());
            sleep(2);
            count--;
        }
        printf("I am child, I quit\n");
    }
    else
    {
        // parent
        while (1) {
            printf("我是父进程,pid:%d ppid:%d\n", getpid(), getppid());
            sleep(2);
        }
    }
    return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        // child
        while(1)
        {
            printf("我是子进程pid:%d, ppdi:%d\n",getpid(),getppid());
            sleep(1);
        }
    }
    else
    {
        // parent
        int cnt = 5;
        while(cnt--)
        {
            printf("我是父进程pid:%d, ppdi:%d\n",getpid(),getppid());
            sleep(1);
        }
    }
    return 0;
}
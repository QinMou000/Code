#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
int main()
{
    pid_t id = fork();
    if(uid == 0){
        // child
        while(1)
        {
            sleep(1);
            printf("我是子进程：%d",getpid());
        }
    }
    else{
        // parent
        while(1)
        {
            sleep(1);
            printf("我是父进程：%d",getpid());
        }
    }
    return 0;
}
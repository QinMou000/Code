#include<stdio.h>
#include<>
int main()
{
    uid_t uid = fork();
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
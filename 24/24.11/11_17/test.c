
#include<stdio.h>
#include<unistd.h>
<<<<<<< HEAD
#include <sys/types.h>
int main()
{
    pid_t id = fork();
    if(uid == 0){
=======
int main()
{
    pid_t id = fork();
    printf("我是一个进程：%d",getpid());
    if(id == 0){
>>>>>>> 19358644daf8db77d0c063f70a949513234da8b5
        // child
        while(1)
        {
            sleep(1);
            printf("我是子进程：%d\n",getpid());
        }
    }
    else{
        // parent
	int cnt = 3;
        while(cnt--)
        {
            sleep(1);
            printf("我是父进程：%d\n",getpid());
        }
    }
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	pid_t id = fork();
//	if(id < 0){
//		perror("fork");
//		return 1;
//	}
//	else if(id > 0){ //parent
//		printf("parent[%d] is sleeping...\n", getpid());
//		sleep(30);
//	}else{
//		printf("child[%d] is begin Z...\n", getpid());
//		sleep(5);
//		exit(EXIT_SUCCESS);
//	}
//	return 0;
//}

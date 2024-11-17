
#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t id = fork();
    printf("我是一个进程：%d",getpid());
    if(id == 0){
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

// #include<stdio.h>

// int main()
// {
//     printf("hello Qin\n");
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     for(int i = 0; i < 150; i++)
//     {
//         printf("[%d]->%s\n",i,strerror(i));
//     }
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     printf("hello Qin!");
//     _exit(1);
//     return 0;
// // }
// #include<stdio.h>
// #include<unistd.h>
// #include<stdlib.h>
// #include<sys/wait.h>
// #include<sys/types.h>
// int main()
// {
//     pid_t id = fork();//创建子进程
//     if(id==0)
//     {
//         //chlld
//         int count = 10;
//         while(count--)
//         {
//             printf("我是子进程，pid:%d，ppid:%d\n",getpid(),getppid());
//             sleep(1);
//         }
//         exit(0);
//     }
//     //father
//     int status = 0;
//     pid_t ret = wait(&status);
//     //如果等待成功
//     if(ret>0)
//     {
//         printf("等待成功！\n");
//         if(WIFEXITED(status))
//         {
//             //退出正常
//             printf("exit code:%d\n",WEXITSTATUS(status));
//         }
//         else
//         {
//             printf("exit signal:%d\n",status&0x7f);
//         }
//     }
//     sleep(5);
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <sys/types.h>
// int main()
// {
// 	pid_t id = fork();
// 	if (id == 0){
// 		//child          
// 		int count = 10;
// 		while (count--){
//             printf("我是子进程，pid:%d，ppid:%d\n",getpid(),getppid());
// 			sleep(1);
// 		}
// 		exit(0);
// 	}
// 	//father           
// 	int status = 0;
// 	pid_t ret = waitpid(id, &status, 0);
// 	if (ret >= 0){
// 		//wait success                    
// 		printf("等待成功！\n");
// 		if (WIFEXITED(status)){
// 			//退出正常                                
// 			printf("exit code:%d\n", WEXITSTATUS(status));
// 		}
// 		else{                             
// 			printf("eixt siganl %d\n", status & 0x7F);
// 		}
// 	}
// 	sleep(10);
// 	return 0;
// }
//#include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// int main()
// {
// 	pid_t ids[10]={0};
// 	for (int i = 0; i < 10; i++){
// 		pid_t id = fork();
// 		if (id == 0){
// 			//child
// 			printf("child process created successfully...PID:%d\n", getpid());
// 			sleep(3);
// 			exit(i); //将子进程的退出码设置为该子进程PID在数组ids中的下标
// 		}
// 		//father
// 		ids[i] = id;
// 	}
// 	for (int i = 0; i < 10; i++){
// 		int status = 0;
// 		pid_t ret = waitpid(ids[i], &status, 0);
// 		if (ret >= 0){
// 			//wait child success
// 			printf("wait child success..PID:%d\n", ids[i]);
// 			if (WIFEXITED(status)){
// 				//exit normal
// 				printf("exit code:%d\n", WEXITSTATUS(status));
// 			}
// 			else{
// 				//signal killed
// 				printf("exit signal %d\n", status & 0x7F);
// 			}
// 		}
// 	}
// 	return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t id=fork();//创建子进程
    if(id==0)
    {
        //child
        int count=3;
        while(count--)
        {
            printf("child do something\n");
            sleep(3);
        }
        exit(0);
    }
    //father
    while(1)
    {
        int status=0;
        pid_t ret=waitpid(id,&status,WNOHANG);
        if(ret>0)
        {
            printf("wait success\n");
            printf("exit code:%d\n",WEXITSTATUS(status));
            break;
        }
        else if(ret==0)
        {
            printf("father do other things\n");
            sleep(1);
        }
        else
        {
            //wait error
            break;
        }
    }
    return 0;
}

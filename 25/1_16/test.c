#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	//c
	printf("hello printf\n");
	fputs("hello fputs\n", stdout);
	//system
	write(1, "hello write\n", 12);
	fork();
	return 0;
}

// int main()
// {
//     close(1); // 关闭标准输出流
//     int fd=open("log.txt", O_WRONLY | O_CREAT, 0666);
//     if(fd<0) 
//     {
//         perror("open fail:");
//         return 1;
//     }
//     //向屏幕打印信息
//     printf("hello printf!\n");
//     close(fd);
//     return 0;
// }         

// int main()
// {
//     int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
//     if(fd < 0)
//     {
//         perror("open fail:");
//         return 1;
//     }
//     close(1);
//     dup2(fd, 1); // 将fd处的指针拷贝到1处，进行重定向
//     printf("hello printf!\n");
//     fprintf(stdout, "hello fprintf!\n");
//     close(fd);
//     return 0;
// }

// int main()
// {
//     printf("stdout:hello printf!\n");
//     perror("stderr:hello perror!");
//     fprintf(stdout,"stdout:hello fprintf!\n");
//     fprintf(stderr,"stderr:hello fprintf!\n");
//     return 0;
// }

// int main()
// {
//     close(0);
//     int fd = open("log.txt", O_RDONLY);
//     if(fd < 0)
//     {
//         perror("open failed");
//         return 1;
//     }
//     char buf[128] = {0};
//     while(scanf("%s", buf) != EOF)
//     {
//         printf("%s\n", buf);
//     }
//     close(fd);
//     return 0;
// }

// int main()
// {
//     close(1); // 关闭标准输出流
//     int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
//     if(fd < 0)
//     {
//         perror("open failed");
//         return 1;
//     }
//     printf("Hello, world\n");
//     printf("Hello, world\n");
//     printf("Hello, world\n");
//     fflush(stdout);
//     close(fd);
//     return 0;
// }
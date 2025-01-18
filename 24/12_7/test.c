#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
    close(0);
    close(2);
	int fd1 = open("log1.txt", O_RDONLY | O_CREAT, 0666);
	int fd2 = open("log2.txt", O_RDONLY | O_CREAT, 0666);
	int fd3 = open("log3.txt", O_RDONLY | O_CREAT, 0666);
	int fd4 = open("log4.txt", O_RDONLY | O_CREAT, 0666);
	int fd5 = open("log5.txt", O_RDONLY | O_CREAT, 0666);
	printf("fd1:%d\n", fd1);
	printf("fd2:%d\n", fd2);
	printf("fd3:%d\n", fd3);
	printf("fd4:%d\n", fd4);
	printf("fd5:%d\n", fd5);
	return 0;
}


// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<fcntl.h>
// #include<string.h>
// int main()
// {
//     int fd = open("log.txt", O_RDONLY);
//     if(fd < 0)
//     {
//         perror("open fail:");
//         return 1;
//     }
//     char buf[1024] = {'\0'};
//     ssize_t ret = read(fd, buf, 1023);
//     if(ret > 0) printf("%s",buf);

//     close(fd);
//     return 0;
// }


// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<fcntl.h>
// #include<string.h>
// int main()
// {
//     int fd = open("log.txt",O_WRONLY | O_CREAT);
//     if(fd < 0)
//     {
//         //open error
//         perror("open fail:");
//         return 1;
//     }
//     const char* msg = "hello QinMou!\n";
//     for(int i = 0; i < 8; i++)
//     {
//         write(fd, msg, strlen(msg));
//     }
//     close(fd);
//     return 0;
// }

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int main()
// {
//     umask(0);//设置文件掩码为0
//     int fd1 = open("log1.txt", O_RDONLY | O_CREAT, 0666);
// 	int fd2 = open("log2.txt", O_RDONLY | O_CREAT, 0666);
// 	int fd3 = open("log3.txt", O_RDONLY | O_CREAT, 0666);
// 	int fd4 = open("log4.txt", O_RDONLY | O_CREAT, 0666);
// 	int fd5 = open("log5.txt", O_RDONLY | O_CREAT, 0666);
// 	printf("fd1:%d\n", fd1);
// 	printf("fd2:%d\n", fd2);
// 	printf("fd3:%d\n", fd3);
// 	printf("fd4:%d\n", fd4);
// 	printf("fd5:%d\n", fd5);
//     return 0;
// }

// int main()
// {
//   //向显示器打印
//   fputs("hello QinMou!\n",stdout);
//   fputs("hello QinMou!\n",stdout);
//   fputs("hello QinMou!\n",stdout);
//   fputs("hello QinMou!\n",stdout);
//   return 0;
// }

// int main()
// {
//     FILE*fp=fopen("log.txt","w");
//     if(fp==NULL)
//     {
//         perror("fopen fail:");
//         return 1;
//     }
//     sleep(100);
//     //open success
//     const char*msg="hello Qin!\n";
//     int count=5;
//     while(count--)
//     {
//         fputs(msg,fp);
//     }
//     fclose(fp);
//     return 0;
// }

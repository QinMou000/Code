#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// 实现父子进程之间的信息通信
void child_write(int fd)
{
    char buffer[1024];
    int cnt = 0;
    while(true)
    {
        snprintf(buffer, sizeof(buffer), "hello father pid:%d",getpid());
        write(fd, buffer, sizeof(buffer) - 1);
        printf("child: %d\n", cnt);
        cnt++;
        // break;
    }
}

void father_read(int fd)
{
    char buffer[1024];
    // int cnt = 0;
    while(true)
    {
        sleep(2);
        size_t n = read(fd, buffer, sizeof(buffer) - 1);
        if(n > 0)
        {
            buffer[n] = 0;
            std::cout << "father has receved the messege:" << buffer << std::endl;
        }
        else
        {
            std::cout << "chlid退出，没意思，我也退了n:" << n << std::endl;
            break;
        }
        // cnt++; // cnt 每隔一秒加一，说明在read时阻塞了
        // break;
    }
}

int main()
{
    // 实现父进程读取子进程
    int fds[2] = {0};
    int n = pipe(fds); // fds[0]是读端，fds[1]是写端
    if(n < 0)
    {
        std::cerr << "pipe error" << std::endl;
        return 1;
    }
    pid_t id = fork();
    if(id == 0) // 在子进程中id返回0
    {
        close(fds[0]); // 关闭子进程的读端
        child_write(fds[1]);
        exit(0);
    }

    close(fds[1]); // 关闭父进程的写端
    father_read(fds[0]);
    waitpid(id, nullptr, 0);
    return 0;
}
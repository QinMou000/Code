#include "NamePipe.hpp"

int main()
{
    NamePipe pipe(SERVER);
    pipe.Open();
    pipe.Fd();
    std::cout << "xxxxxxxxxx" << std::endl;
    pipe.Operate();
    return 0;
}


// int main()
// {
//     // 1. 创建命名管道文件
//     umask(0);
//     int n = mkfifo(PATH_NAME, 0666);
//     if (n < 0)
//         EXIT("mkfifo");
//     else
//         std::cout << "mk success" << std::endl;
//     // 2.管道文件已经有了，直接打开即用
//     int fd = open(PATH_NAME, O_RDONLY);
//     if (fd < 0)
//         EXIT("open");
//     else
//         std::cout << "open success" << std::endl;

//     // 3.从管道里读数据
//     char s[1024] = {0};
//     while (1)
//     {
//         int n = read(fd, s, sizeof(s) - 1);
//         if(n < 0)
//             EXIT("read");
//         if(n == 0)
//             break;
//         s[1023] = '0';
//         printf("%s\n", s);
//     }

//     // 4.关闭文件
//     close(fd);
//     std::cout << "close success" << std::endl;

//     // 5.删除管道文件
//     unlink(PATH_NAME);
//     std::cout << "unlink success" << std::endl;

//     return 0;
// }
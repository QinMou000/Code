#include "NamePipe.hpp"

int main()
{
    NamePipe pipe(CLIENT);
    pipe.Open();
    pipe.Fd();
    pipe.Operate();
    return 0;
}

// int main()
// {
//     // 1.以写方式打开文件
//     int fd = open(PATH_NAME, O_WRONLY);
//     if (fd < 0)
//         EXIT("open");
//     else
//         std::cout << "open success" << std::endl;

//     // 2.往管道里面写数据
//     while (true)
//     {
//         std::string s;
//         std::cout << "please type:";
//         std::cin >> s;
//         write(fd, s.c_str(), sizeof(s) - 1);
//     }
//     // 3.关闭文件
//     close(fd);
//     std::cout << "close success" << std::endl;

//     return 0;
// }
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define CLIENT 0
#define SERVER 1
#define PATH_NAME "./fifo"

#define EXIT(m)             \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

class NamePipe
{
private:
    void OpenForWrite()
    {
        // 以写方式打开文件
        _fd = open(PATH_NAME, O_WRONLY); // 这里不能写int _fd 这会新建一个局部变量，
                                         // 后续打开文件也返回到了这个局部变量中，而成员变量_fd没有被更新
        std::cout << "opend fd:" << _fd << std::endl;

        if (_fd < 0)
            EXIT("open");
        else
            std::cout << "openforwrite success" << std::endl;
    }
    void OpenForRead()
    {
        // 以读方式打开文件
        _fd = open(PATH_NAME, O_RDONLY); // 这里的道理同OpenForWrite();
        std::cout << "opend fd:" << _fd << std::endl;

        if (_fd < 0)
            EXIT("open");
        else
            std::cout << "openforread success" << std::endl;
    }
    void Create()
    {
        // 创建命名管道文件
        umask(0);
        int n = mkfifo(PATH_NAME, 0666);
        if (n < 0)
            EXIT("mkfifo");
        else
            std::cout << "mk success" << std::endl;
    }
    void Delete()
    {
        // 删除管道文件
        unlink(PATH_NAME);
        std::cout << "unlink success" << std::endl;
    }
    void Write()
    {
        // 往管道里面写数据
        while (true)
        {
            std::string s;
            std::cout << "please type:";
            std::cin >> s;
            write(_fd, s.c_str(), sizeof(s) - 1);
        }
    }
    void Read()
    {
        // 从管道里读数据
        char s[1024] = {0};
        while (true)
        {
            //std::cout << "ready for read" << std::endl;
            int n = read(_fd, s, sizeof(s) - 1);
            //std::cout << "read over" << std::endl;
            //std::cout << "n:" << n << std::endl;
            //std::cout << "_fd" << _fd << std::endl;

            if (n < 0)
            {
                std::cout << "n:" << n << std::endl;
                EXIT("read");
            }
            if (n == 0)
            {
                std::cout << n << std::endl;
                break;
            }
            s[1023] = '0';
            printf("%s\n", s);
        }
    }

public:
    NamePipe(int usr)
        : _usr(usr),
          _fd(-1)
    {
        if (_usr == SERVER) // 如果身份为服务端，则创建管道文件
            Create();
    }
    void Open()
    {
        if (_usr == CLIENT)
            OpenForWrite();
        else if (_usr == SERVER)
            OpenForRead();
        else
            std::cout << "Open erro" << std::endl;
    }
    void Operate()
    {
        if (_usr == CLIENT)
            Write();
        else if (_usr == SERVER)
            Read();
        else
            std::cout << "Operate erro" << std::endl;
    }
    ~NamePipe()
    {
        // 关闭文件
        close(_fd);
        std::cout << "close success" << std::endl;
        if (_usr == SERVER) // 如果身份为服务端，则删除管道文件
            Delete();
    }
    int Fd()
    {
        return _fd;
    }

private:
    int _fd;
    int _usr;
};
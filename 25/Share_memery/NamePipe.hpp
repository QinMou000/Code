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
        _fd = open(PATH_NAME, O_WRONLY | O_NONBLOCK); // 加上非阻塞模式
                                                      // 这里不能写int _fd 这会新建一个局部变量，
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
        _fd = open(PATH_NAME, O_RDONLY | O_NONBLOCK); // 加上非阻塞模式
                                                      // 这里的道理同OpenForWrite();
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
    void WakeUp()
    {
        // 往管道里面写数据,随便写，用于唤醒
        int ret = 1;
        write(_fd, &ret, 4);
    }
    bool IsSend()
    {
        int ret;
        int n = read(_fd, &ret, 4);
        return ret == 1;
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
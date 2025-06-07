#pragma once
#include "Common.hpp"
#include "Socket.hpp"
#include <sys/select.h>

// using server_t = std::function<void(std::shared_ptr<Socket> &sock, InetAddr &addr)>;

const static size_t size = 1024;

class SelectServer
{
public:
    SelectServer(uint16_t port /*, server_t server*/)
        : _port(port),
          _listensocket(std::make_unique<TcpSocket>()),
          // _server(server),
          _array(size, -1)
    {
        _listensocket->BuildTcpSocket(_port); // 初始化套接字
        _array[0] = _listensocket->Fd();      // 规定辅助数组的第一个元素为listen
        _max_fd = _array[0];
    }
    ~SelectServer() {}
    void Printfd()
    {
        for (int fd : _array)
        {
            if (fd == -1)
                continue;
            std::cout << fd << " ";
        }
        std::cout << std::endl;
    }
    void Start()
    {
        _isrunning = true;
        while (_isrunning)
        {
            Printfd();
            fd_set rfds;
            FD_ZERO(&rfds);
            for (int fd : _array)
            {
                if (fd == -1)
                    continue;
                FD_SET(fd, &rfds); // 设置有效fd
                if (_max_fd < fd)
                    _max_fd = fd; // 更新最大的fd
            }
            int n = select(_max_fd + 1, &rfds, NULL, NULL, NULL); // 只关心读fd 并且阻塞等待
            if (n > 0)
                Dispatcher(rfds); // 有fd准备就绪了就交给事件派发器
            else if (n == 0)
                LOG(LogLevel::WARNING) << "Time out!";
            else
                LOG(LogLevel::WARNING) << "Select error!";
        }
        _isrunning = false;
    }
    // 事件派发器
    void Dispatcher(fd_set &rfds)
    {
        for (int i = 0; i < _array.size(); i++)
        {
            if (_array[i] == -1)
                continue;
            if (FD_ISSET(_array[i], &rfds)) // fd 合法且就绪
                if (_array[i] == _listensocket->Fd())
                    Accepter(); // listen套接字有效，accept后将新fd放入辅助数组
                else
                    Recever(i); // 可读/可写 套接字有效，给IO处理器处理
        }
    }
    // 链接管理器
    void Accepter()
    {
        InetAddr client;
        int sockfd = _listensocket->Accept(&client);
        LOG(LogLevel::INFO) << "new link client: " << client.StringAddr();
        if (sockfd >= 0)
        {
            int pos;
            for (pos = 0; pos < size; pos++)
                if (_array[pos] == -1) // 找到辅助数组中可用的位置
                    break;
            // pos位置可用
            if (pos == size)
                LOG(LogLevel::ERROR) << "select server full!"; // 数组不够用了
            else
                _array[pos] = sockfd;
        }
    }
    // IO处理器
    void Recever(int pos)
    {
        char buffer[1024];
        ssize_t n = recv(_array[pos], buffer, sizeof(buffer) - 1, 0);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "client say@" << buffer;
        }
        else if (n == 0) // 客户端关闭链接
        {
            LOG(LogLevel::INFO) << "client close link";
            close(_array[pos]); // 关闭文件描述符
            _array[pos] = -1;   // 取消select托管
        }
        else // 错误
        {
            LOG(LogLevel::INFO) << "recv error!";
            close(_array[pos]);
            _array[pos] = -1;
        }
    }
    void Stop()
    {
        _isrunning = false;
    }

private:
    std::unique_ptr<Socket> _listensocket; // 用这个套接字专门来供父进程监听
    uint16_t _port;
    bool _isrunning;
    // server_t _server; // 外面传的server函数，可以是上层调用

    std::vector<int> _array;
    int _max_fd;
};
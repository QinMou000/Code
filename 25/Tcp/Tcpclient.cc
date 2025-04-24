#include "Tcpserver.hpp"
#include "Socket.hpp"
#include "Common.hpp"
#include "Protocol.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " ip " << "port " << std::endl;
}

void GetDataFromStdin(int &x, int &y, char &oper)
{
    std::cout << "please enter x:";
    std::cin >> x;
    std::cout << "please enter y:";
    std::cin >> y;
    std::cout << "please enter oper:";
    std::cin >> oper;
}

// ./client ip port
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }
    std::string server_ip = argv[1];
    uint16_t server_port = std::stoi(argv[2]);

    InetAddr server(server_ip, server_port);

    std::unique_ptr<Socket> client = std::make_unique<TcpSocket>();

    client->BuildTcpSocketForClient();

    if (client->Connect(server) != 0)
    {
        LOG(LogLevel::ERROR) << "Connect error";
        exit(CONNECT_ERR);
    }

    std::unique_ptr<Protocol> protocol = std::make_unique<Protocol>();

    while (1)
    {
        int x, y;
        char oper;

        GetDataFromStdin(x, y, oper); // 输入对应数据

        std::string sendstr = protocol->BuildRequestStr(x, y, oper); // 直接将请求转化为可以发送的字符串

        client->Send(sendstr); // 发送给服务器

        Response res; // 建立一个回复对象

        std::string recv_str;

        int n = client->Recv(&recv_str);
        if (n > 0)
        {
            std::string json_str;

            while (protocol->Decode(recv_str, json_str)) // 去掉报头，剩下json串
            {
                res.Deserialize(json_str); // 反序列化
            }
            res.Show();
        }
    }

    return 0;
}
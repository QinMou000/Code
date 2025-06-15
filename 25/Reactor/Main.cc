#include <iostream>
#include <memory>
#include "Reactor.hpp"
#include "Listener.hpp"
#include "Http.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage " << proc << " port" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }

    uint16_t port = std::stoi(argv[1]);

    std::unique_ptr<Http> http = std::make_unique<Http>();

    std::shared_ptr<Connection> Con = std::make_shared<Listener>(port);

    Con->SetHander([&http](std::string &inbuffer) -> std::string
                   { return http->HanderRequest(inbuffer); }); // TODO

    std::unique_ptr<Reactor> R = std::make_unique<Reactor>();

    R->AddConnection(Con);

    R->Loop();

    return 0;
}
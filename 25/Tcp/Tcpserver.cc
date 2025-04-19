#include "Tcpserver.hpp"
#include "Common.hpp"


void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " -port " << std::endl;
}


// ./server -port
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }
    std::string server_port = argv[1]; 

    


    return 0;
}
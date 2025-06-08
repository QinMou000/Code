#include "Reactor.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage " << proc << " port" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        Usage(argv[0]);


        
    return 0;
}
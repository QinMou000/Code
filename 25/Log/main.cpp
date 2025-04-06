#include "log.hpp"


using namespace LogModule;

int main()
{
    while(true)
    {
        LOG(LogLevel::DEBUG) << "hello";
        sleep(1);
    }
    return 0;
}
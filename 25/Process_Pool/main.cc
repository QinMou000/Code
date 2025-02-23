#include "Process_Pool.hpp"

int main()
{
    process_pool pp;

    pp.Start();

    int count = 5;
    while (count--)
    {
        sleep(1);
        pp.Run();
    }


    pp.Stop();
    

    return 0;
}
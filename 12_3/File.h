#include<unistd.h>
#include<stdlib.h>

struct FILE
{
    int flag;
    
    char buffer[1024];
}

my_openfile
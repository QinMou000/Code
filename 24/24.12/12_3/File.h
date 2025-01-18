#include<unistd.h>
#include<stdlib.h>


#define NONE_flush 1<<0
#define LINE_flush 1<<1
#define FULL_flush 1<<2

#define MAX 1024

struct FILE
{
    int flag;
    int flush_method;
    int fileno;
    char buffer[MAX];
    int buffer_len;
}


my_openfile
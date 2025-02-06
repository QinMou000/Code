#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

#define NONE_flush 1<<0
#define LINE_flush 1<<1
#define FULL_flush 1<<2

#define MAX 1024

typedef struct MYFILE
{
    int flag;         // 底层调用open时文件的打开方式
    int flush_method; // 缓冲区刷新模式
    int fileno;       // 文件标识符
    char buffer[MAX]; // 缓冲区
    int buffer_len;   // 缓冲区长度
}MYFILE;

MYFILE* my_openfile(const char* path, const char* mode);
void my_closefile(MYFILE* file);
int my_fwrite(MYFILE* file, void * str, int len);
void my_fflush(MYFILE* file);

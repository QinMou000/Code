#include"File.h"

static MYFILE* buy_file(int fd, int flag)
{
    MYFILE* file = (MYFILE*)malloc(sizeof(MYFILE));
    if(file == NULL) return NULL;
    file->buffer_len = 0;
    file->fileno = fd;
    file->flag = flag;
    file->flush_method = LINE_flush;
    memset(file->buffer,0,sizeof(file->buffer_len));
    return file;
}

MYFILE* my_openfile(const char* path, const char* mode)
{
    int fd = -1;
    int flag = 0;
    if(strcmp(mode,"w") == 0) // 对文件进行写操作
    {
        flag = O_CREAT | O_WRONLY | O_TRUNC;
        fd = open(path,flag,0666);
    }
    else if(strcmp(mode,"a") == 0) // 对文件进行追加写操作
    {
        flag = O_CREAT | O_WRONLY | O_APPEND;
        fd = open(path,flag,0666);
    }
    else if(strcmp(mode,"r") == 0) // 对文件进行读操作
    {
        flag = O_RDWR;
        fd = open(path,flag);
    }
    else
    {
        // ...
    }
    if(fd < 0) return NULL;
    return buy_file(fd,flag);
}

void my_closefile(MYFILE* file)
{
    if(file == NULL) return;
    if(file->fileno < 0) return;
    my_fflush(file);
    close(file->fileno);// 返回0关闭成功，-1关闭失败
    free(file);
}

int my_fwrite(MYFILE* file, void * str, int len)
{
    // 1、将东西拷贝到buffer里面
    memcpy(file->buffer + file->buffer_len, str, len);
    file->buffer_len += len;

    // 2、判断是否满足刷新条件
    // （遇到\n就刷新，buffer满了就刷新）
    if(file->buffer[file->buffer_len - 1] == '\n' 
    && file->flush_method == LINE_flush)
    {
        my_fflush(file);
    }
    if(strlen(file->buffer) == file->buffer_len - 1) // 缓冲区满了，全刷新
    {
        my_fflush(file);
    }

    return 0;
}

void my_fflush(MYFILE* file)
{
    // 系统调用write往内核级缓冲区些东西`
    // write返回的是向缓冲区写入的字节个数，错误返回-1
    if(file->buffer_len == 0) return;
    write(file->fileno,file->buffer,file->buffer_len);
    // memset(file->buffer,0,file->buffer_len); 不用清空，下次写的时候会覆盖
    file->buffer_len = 0;
    // void(n); // 这个n后续可能有用吧~
}

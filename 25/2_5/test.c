#include "File.h"

int main()
{
    MYFILE* file = my_openfile("log.txt","w");
    char* str = "abcdef";
    my_fwrite(file, str, strlen(str));
    my_closefile(file);

    return 0;
}
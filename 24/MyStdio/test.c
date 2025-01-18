#include"File.h"

int main()
{
    MYFILE* f = my_openfile("log.txt", "w");
    char* str = "wwwwwwwwwww\n";
    int len = strlen(str);
    my_fwrite(f, str, len);
    my_closefile(f);
    return 0;
}

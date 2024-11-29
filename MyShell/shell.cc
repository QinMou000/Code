#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
    printf("%s@VM-4-4-%s:%s#\n",getenv("USER"),getenv("USER"),getenv("PATH"));
    return 0;
}

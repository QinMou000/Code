#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

bool isValid(char* s) {
    Stack ST;
    StackInit(&ST);
    while (*s)
    {
        printf("%s", s);
        if (*s == '(' || *s == '[' || *s == '{')
            StackPush(&ST, *s);
        if (*s == StackTop(&ST))
            StackPop(&ST);
        s++;
    }
    printf("%d", StackIsEmpty(&ST));
    return StackIsEmpty(&ST);
}


int main()
{
    char* s = "[";
    isValid(s);

	return 0;
}
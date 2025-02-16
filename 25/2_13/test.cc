#include <stdlib.h>
#include <stdio.h>

int main() 
{
    void *allocs[100];
    int i, j;
    FILE *urandom = fopen("/dev/urandom", "r");

    for (i = 0; i < 100; ++i) {
        allocs[i] = malloc(1024 * 1024 * 1024);
        if (!allocs[i]) {
            printf("malloc for i = %d failed\n", i);
            return 1;
        }
        fread(allocs[i], 1024, 1, urandom);
    }

    for (i = 0; i < 100; ++i)
        free(allocs[i]);
    fclose(urandom);

    return 0;
}
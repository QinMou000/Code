// #include <stdlib.h>
// #include <stdio.h>

// int main() 
// {
//     void *allocs[100];
//     int i, j;
//     FILE *urandom = fopen("/dev/urandom", "r");

//     for (i = 0; i < 100; ++i) {
//         allocs[i] = malloc(1024 * 1024 * 1024);
//         if (!allocs[i]) {
//             printf("malloc for i = %d failed\n", i);
//             return 1;
//         }
//         fread(allocs[i], 1024, 1, urandom);
//     }

//     for (i = 0; i < 100; ++i)
//         free(allocs[i]);
//     fclose(urandom);

//     return 0;
// }

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("lfs-test", O_RDONLY);

    if (fd == -1) {
        perror("open() failed");
        return 1;
    }

    close(fd);
    return 0;
}
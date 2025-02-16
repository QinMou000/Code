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
#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

char *get_next_line(int fd) {
    static char str[BUFFER_SIZE * 2];
    char *ptr = str;
    char *line;

    if (fd < 0)
        return NULL;

    while (1) {
        if (ptr - str >= BUFFER_SIZE * 2) {
            ptr = str;
        }

        ssize_t z = read(fd, ptr, BUFFER_SIZE);

        if (z < 0)
            return NULL;
        ptr[z] = '\0';

        if (z == 0 && ptr == str) {
            return NULL;
        }
        line = strchr(ptr, '\n');

        if (line != NULL) {
            *line = '\0';
            ptr = line + 1;
            return str;
        }
        ptr += z;
    }
}

int main() {
    int fd = open("txt.txt", O_RDWR);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}


// this is line nb 2
// this is line nb 3
// this is line nb 4
// this is line nb 5
// this is line nb 6
// this is line nb 7
// this is line nb 8
// this is line nb 9
// this is line nb 10
// this is line nb 11
// this is line nb 12
// this is line nb 13
// this is line nb 14
// this is line nb 15
// this is line nb 16
// this is line nb 17
// this is line nb 18
// this is line nb 19
// this is line nb 20
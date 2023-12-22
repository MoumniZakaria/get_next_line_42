
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *sta;
    char *rst ;
    char *buffer;
    int len;
    while (1)
    {
        if(ft_strchr(sta, '\n'))
            break;
        len = read(fd, buffer, BUFFER_SIZE);
        buffer[len] = '\0';
        if (len == -1)
            return (free(sta), free(buffer),NULL);
        if (len == 0)
            break;
        sta = ft_strjoin(sta,buffer);
        puts(sta);
    }
}
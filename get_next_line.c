/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:34:35 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/19 20:29:34 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *sta;
    char *rst ;
    char *buffer;
    int len;
    int i;
    
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return(NULL);
    len = 1;
    while (1)
    {
        if (len < 0)
        {
            free(buffer);
            free(rst);
            return(NULL);
        }
        len = read(fd, buffer, BUFFER_SIZE);
        buffer[len] = '\0';
        if(!ft_strchr(buffer, '\n'))
        {
            sta = ft_strjoin(sta, buffer);
            if(len < BUFFER_SIZE)
                rst = ft_strdup(sta);
        }
        else
        {
            i = 0;
            while (buffer[i] !='\n')
                i++;
            rst = ft_strjoin(sta,ft_substr(buffer, 0, i));
            free(sta);
            sta = ft_substr(buffer, i , (BUFFER_SIZE - i));
            break;
        }
        buffer[0]= 0;
        // puts(buffer);
        // printf("%s",sta);
        // printf("\n%d\n",len);
        if (len == 0 || len < 0)
            break;
    }
    return(rst);
}

int main()
{
    int fd = open("txt.txt",O_RDONLY);
    // printf("%d",fd);
    printf("%s",get_next_line(fd));
    printf("\n");
    printf("%s",get_next_line(fd));
    // printf("\n2");
    // printf("%s",get_next_line(fd));
    // printf("\n3");
    // printf("%s",get_next_line(fd));
    return 0;
}


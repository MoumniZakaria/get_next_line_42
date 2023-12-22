/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:34:35 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/22 16:32:31 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_1(char *str)
{
    int     i;
    char    *s;
    
    i = 0;
    if(!str)
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    s = ft_substr(str, 0, (i + 1));
    return (s);
}
char *check_2(char *str)
{
    int     i;
    char    *s;
    
    i = 0;
    if(!str)
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    s = ft_substr(str, (i + 1), (ft_strlen(str) - (i + 1)));

    return (s);
}
char *get_next_line(int fd)
{
    static char *sta;
    char *rst ;
    char *buffer;
    int len;
    if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1); // cast to sizet
    if(!buffer)
        return(free(buffer), NULL);
    while (1)
    {
    
        if(ft_strchr(sta, '\n'))
            break;
        len = read(fd, buffer, BUFFER_SIZE);
        if (len == 0)
            break;
        if (len == -1)
            return (free(sta), free(buffer),NULL);
        buffer[len] = '\0';
        sta = ft_strjoin(sta,buffer);
    }
    free(buffer);
    rst = check_1(sta);
    sta = check_2(sta);
    return(rst);
}

// int main()
// {
//     int fd = open("txt.txt",O_RDONLY);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // char *str="hello\n\n\n\n\n\n\n\n\nworld";
//     // printf("{%s}",check_1(str));
//     // printf("{%s}",check_2(str));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:34:35 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/20 20:23:51 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *check_2(char *sta)
{
    int i;
    char *tmp;
    
    i = 0;
    if(!sta)
        return (NULL);
    tmp = ft_strdup(sta);
    int len = 0;
    len = ft_strlen(tmp);
    free(sta);
    while (tmp[i] &&tmp[i] != '\n')
        i++;
    sta = ft_substr(tmp, i + 1, len);
    free(tmp);
    return (sta);
}
char *check_1(char *sta)
{
    
    int i;
    i = 0;
    if(!sta)
        return (NULL);
    while (sta[i] != '\0')
    {
        if (sta[i] == '\n' || sta[i + 1] == '\0')
            return (ft_substr(sta, 0, i + 1));    
        i++;
    }
    return(sta);
}
char *get_next_line(int fd)
{
    static char *sta;
    char *rst ;
    char *buffer;
    int len;
    if (read(fd,NULL,0) == -1)
        return (free(sta), sta = NULL, NULL);
    if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if(!buffer)
        return(NULL);
    len = 1;
    while (1)
    {
        if(sta && *sta && ft_strchr(sta, '\n'))
            break;
        len = read(fd, buffer, BUFFER_SIZE);
        if (len == 0)
            break;
        buffer[len] = '\0';
        sta = ft_strjoin(sta,buffer);
        // printf("\n|||%s|||",sta);
        if (len == -1)
            return (free(sta), free(buffer),NULL);
    }
    free(buffer);
    rst = NULL;
    rst = check_1(sta);
    if(!rst || *rst == '\0')
        return(NULL);
    sta = check_2(sta);
    // if(!sta || *sta == '\0')
    //     return(NULL);
    return(rst);
}

// int main()
// {
//     int fd = open("txt.txt",O_RDONLY);
//     printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));

//     return 0;
// }


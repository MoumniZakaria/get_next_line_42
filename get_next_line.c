/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:34:35 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/18 17:40:08 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *check_static(char *bfr, char *rst)
{
        
}
char *check_bfr(char *bfr, char *rst)
{
    static char *rst;
    
    if()
        return();
    else
        
}
char *get_next_line(int fd)
{
    ssize_t len;
    int i;
    static char *bfr;
    char *rst;
    char *tmp;
    
    tmp = NULL;
    rst = NULL;

    if (fd < 0)
        return (NULL);
    
    while (1)
    {
        len = read(fd, tmp, BUFFER_SIZE);
        tmp = malloc(BUFFER_SIZE + 1);
        if(!tmp)
            return(NULL);
        if (len < 0)
        {
            free(tmp);
            free(rst);
            return(NULL);
        }
        if (len == 0)
            break;
        
            
    }
    return(rst);
}

int main()
{
    int fd = open("txt.txt",O_RDONLY);
    // printf("%d",fd);
    printf("%s",get_next_line(fd));
    return 0;
}


// if (!ft_strchr(tmp,'\n'))
//         {
//             rst = ft_strjoin(rst,ft_strchr(tmp,'\n'));
//         }
//         else
//         {
//             rst = ft_strchr(tmp,'\n');
//             i = 0;
//             while (tmp[i] != '\n')
//                 i++;
//             bfr = ft_substr(tmp,i,BUFFER_SIZE - i);
//         }
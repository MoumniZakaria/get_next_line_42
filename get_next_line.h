/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:02 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/18 17:22:22 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
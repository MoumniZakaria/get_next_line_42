/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:39 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/23 09:09:46 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_1(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = ft_substr(str, 0, (i + 1));
	return (s);
}

char	*check_2(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = ft_substr(str, (i + 1), (ft_strlen(str) - (i + 1)));
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*sta[OPEN_MAX];
	char		*rst;
	char		*buffer;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX
		|| read(fd, NULL, 0) == -1)
		return (free(sta[fd]), sta[fd] = NULL, NULL);
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (free(buffer), NULL);
	len = 1;
	while (len)
	{
		if (ft_strchr(sta[fd], '\n'))
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (free(sta[fd]), free(buffer), NULL);
		buffer[len] = '\0';
		sta[fd] = ft_strjoin(sta[fd], buffer);
	}
	free(buffer);
	rst = check_1(sta[fd]);
	return (sta[fd] = check_2(sta[fd]), rst);
}

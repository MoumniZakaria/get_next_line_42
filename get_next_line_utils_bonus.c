/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumni <zmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:46 by zmoumni           #+#    #+#             */
/*   Updated: 2023/12/22 18:27:40 by zmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;
	int		len;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tmp;
	size_t	len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (free(s1), NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	return (tmp[i] = '\0', free(s1), tmp);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tbl;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (NULL);
	if (len >= ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	tbl = (char *)malloc(sizeof(char) * (len + 1));
	if (!tbl)
		return (NULL);
	while (i < len)
	{
		tbl[i] = s[start];
		i++;
		start++;
	}
	tbl[len] = '\0';
	return (tbl);
}

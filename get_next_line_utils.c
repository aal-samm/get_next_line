/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-samm <aal-samm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:16:40 by aal-samm          #+#    #+#             */
/*   Updated: 2024/03/01 01:15:39 by aal-samm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_calloc(int count, int size)
{
	int		i;
	char	*n_mem;

	i = 0;
	n_mem = malloc(count * size);
	if (!n_mem)
		return (0);
	while (i < (count * size))
	{
		n_mem[i] = 0;
		i++;
	}
	return ((void *)n_mem);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if ((unsigned char)s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*appended;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	appended = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!appended || !s1 || !s2)
		return (NULL);
	while (i < len_s1)
	{
		appended[i] = s1[i];
		i++;
	}
	while (i < len_s2 + len_s1)
	{
		appended[i++] = *s2;
		s2++;
	}
	appended[i] = '\0';
	return (free(s1), s1 = NULL, appended);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub_str;
	unsigned int	new_size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc (1, 1));
	new_size = ft_strlen(&s[start]);
	i = 0;
	if (new_size > len)
		sub_str = ft_calloc (len + 1, 1);
	else
		sub_str = ft_calloc(new_size + 1, 1);
	if (!sub_str)
		return (0);
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	return ((char *)sub_str);
}

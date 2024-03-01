/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-samm <aal-samm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:11:32 by aal-samm          #+#    #+#             */
/*   Updated: 2024/03/01 02:35:03 by aal-samm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

char	*get_next_line(int fd);
void	*ft_calloc(int count, int size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

char	*extract_line(char **line, char *buffer);
void	obtain_remaining(char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_bzero(void *ptr, size_t num);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
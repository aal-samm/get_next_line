/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-samm <aal-samm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:05:10 by aal-samm          #+#    #+#             */
/*   Updated: 2024/02/27 23:23:24 by aal-samm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	*strptr;
// 	char		*buffer;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	strptr = ft_read_line();
// 	if (!strptr)
// 		return (0);
// 	buffer = ft_print_line();
// 	if (!buffer)
// 		return (0);
// }
// `

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buffer_temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer_temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = read();
}

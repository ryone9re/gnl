/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 06:26:58 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/07 12:37:29 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	if (count && size && size > SIZE_MAX / count)
	{
		errno = ENOMEM;
		return (NULL);
	}
	p = (unsigned char *)malloc(size * count);
	if (p)
	{
		i = 0;
		while (i < count * size)
			*(p + i++) = '\0';
	}
	return ((void *)p);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

size_t	ft_strsncpy(char *dest, char *src, size_t start, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[start + i] = src[i];
		i++;
	}
	return (start + i);
}

size_t	has_break(char *str)
{
	size_t	len;
	size_t	i;

	if (!str)
		return (0);
	len = ft_strlen(str);
	i = 0;
	while (i < len && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

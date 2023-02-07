/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:57:02 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/07 13:59:24 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append(char *fwd, char *bck)
{
	size_t	blen;
	char	*ret;

	blen = ft_strlen(bck);
	if (fwd)
		ret = ft_calloc(ft_strlen(fwd) + blen + 1, sizeof(char));
	else
		ret = ft_calloc(blen + 1, sizeof(char));
	if (!ret)
	{
		if (fwd)
			free(fwd);
		return (NULL);
	}
	ft_strsncpy(ret, bck, ft_strsncpy(ret, fwd, 0, ft_strlen(fwd)), blen);
	if (fwd)
		free(fwd);
	return (ret);
}

void	init(char *buf, char *cur, size_t start, size_t nbytes)
{
	size_t	i;
	size_t	clen;

	i = 0;
	if (!cur)
	{
		while (i < nbytes)
			buf[i++] = '\0';
		return ;
	}
	clen = ft_strlen(cur);
	while (start + i < clen && i < nbytes)
	{
		buf[i] = cur[start + i];
		i++;
	}
	while (i < nbytes)
		buf[i++] = '\0';
}

char	*cp_until_nl(char *cur)
{
	size_t	nlp;
	char	*ret;

	if (!cur)
		return (NULL);
	nlp = has_break(cur);
	ret = (char *)ft_calloc(nlp + 1, sizeof(char));
	if (!ret)
	{
		free(cur);
		return (NULL);
	}
	ft_strsncpy(ret, cur, 0, nlp);
	free(cur);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*cur;
	ssize_t		rs;
	static char	buf[BUFFER_SIZE + 1] = {};

	cur = NULL;
	if (buf[0])
		cur = append(NULL, buf);
	while (1)
	{
		if (has_break(cur))
			break ;
		init(buf, NULL, 0, BUFFER_SIZE);
		rs = read(fd, buf, BUFFER_SIZE);
		if (rs == 0)
			return (cur);
		if (rs < 0)
			return (sfree(cur));
		cur = append(cur, buf);
		if (!cur)
			return (NULL);
	}
	init(buf, cur, has_break(cur), BUFFER_SIZE);
	return (cp_until_nl(cur));
}

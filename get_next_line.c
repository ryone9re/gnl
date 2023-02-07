/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:57:02 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/07 12:51:06 by rkurimot         ###   ########.fr       */
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
			buf[i] = '\0';
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

char	*read_append(char *cur, int fd, char *buf, size_t nbytes)
{
	ssize_t	rs;
	char	*ret;

	rs = read(fd, buf, nbytes);
	if (rs < 0)
	{
		if (cur)
			free(cur);
		return (NULL);
	}
	if (rs == 0)
		return (cur);
	ret = append(cur, buf);
	if (!ret)
		return (NULL);
	init(buf, NULL, 0, nbytes);
	return (ret);
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
	static char	buf[BUFFER_SIZE + 1] = {};

	cur = NULL;
	if (buf[0])
		cur = append(NULL, buf);
	else
		cur = read_append(NULL, fd, buf, BUFFER_SIZE);
	while (cur && !has_break(cur))
		cur = read_append(cur, fd, buf, BUFFER_SIZE);
	if (!cur)
		return (NULL);
	init(buf, cur, has_break(cur), BUFFER_SIZE);
	return (cp_until_nl(cur));
}

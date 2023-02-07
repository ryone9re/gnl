/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:36:53 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/07 13:31:05 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <errno.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	init(char *buf, char *cur, size_t start, size_t nbytes);
char	*append(char *fwd, char *bck);
char	*cp_until_nl(char *cur);
char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
size_t	ft_strsncpy(char *dest, char *src, size_t start, size_t size);
size_t	has_break(char *str);
void	*sfree(void *p);

#endif /* GET_NEXT_LINE_H */

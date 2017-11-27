/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/27 16:39:56 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char		*strnjoin_realloc(char *s1, char *s2, size_t n)
{
	char			*ret;
	char			*tmp;
	char			*tmp2;
	size_t			i;

	i = 0;
	tmp2 = s1;
	if (!(tmp = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ret = tmp;
	while (*s1)
		*(tmp++) = *(s1++);
	while (i++ < n)
		*(tmp++) = *(s2++);
	*(tmp) = '\0';
	free(tmp2);
	return (ret);
}

static void		shift_array(char *arr, int shift, int len)
{
	int				i;

	i = 0;
	while (i < shift)
		arr[i++] = '\0';
	while (i < len)
	{
		arr[i - shift] = arr[i];
		arr[i] = '\0';
		i++;
	}
}

static t_buff	*get_buff(t_buff **bufflst, int fd)
{
	t_buff			*tmp;

	if (!bufflst || !*bufflst)
	{
		*bufflst = (t_buff*)malloc(sizeof(t_buff));
		(*bufflst)->fd = fd;
		(*bufflst)->next = NULL;
		return (*bufflst);
	}
	tmp = *bufflst;
	if (tmp->fd == fd)
		return (tmp);
	while (tmp->next)
	{
		if (tmp->next->fd == fd)
			return (tmp->next);
		tmp = tmp->next;
	}
	tmp->next = (t_buff*)malloc(sizeof(t_buff));
	tmp->next->fd = fd;
	tmp->next->next = NULL;
	return (tmp->next);
}

static int		read_to_buff(int fd, char *buff)
{
	int				rb;

	rb = 0;
	if (!*buff)
	{
		rb = read(fd, buff, BUFF_SIZE);
		buff[rb] = '\0';
	}
	return (rb);
}

int				get_next_line(int fd, char **line)
{
	static	t_buff	*buffs;
	t_buff			*buff;
	int				rbt;
	size_t			llen;
	size_t			blen;

	if (!line)
		return (-1);
	buff = get_buff(&buffs, fd);
	*line = ft_strnew(0);
	rbt = 0;
	blen = 0;
	llen = 0;
	while (blen == llen)
	{
		rbt += read_to_buff(fd, buff->buff);
		blen = ft_strlen(buff->buff);
		llen = (!ft_strchr((const char*)buff->buff, '\n')) ? blen
			: ft_strchr((const char *)buff->buff, '\n') - buff->buff;
		*line = strnjoin_realloc(*line, buff->buff, llen);
		if (llen == 0 && blen == 0)
			break ;
		shift_array(buff->buff, llen + 1, BUFF_SIZE);
		rbt++;
	}
	return ((rbt > 0) ? 1 : rbt);
}

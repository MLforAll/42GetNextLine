/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/15 16:10:19 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_backup bak;

static size_t	ft_strlenline(char *str, char c)
{
	size_t	ret;

	ret = 0;
	while (*str)
	{
		if (*str == c)
			break ;
		ret++;
		str++;
	}
	return (ret);
}

static char		*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ret = tmp;
	while (*s1)
		*(tmp++) = *(s1++);
	while (i++ < n)
		*(tmp++) = *(s2++);
	*(tmp) = '\0';
	return (ret);
}

static void 	strnjoin_realloc(char **s1, char *s2, size_t n)
{
	char	*tmp;

	tmp = *s1;
	*s1 = ft_strnjoin(*s1, s2, n);
	free(tmp);
}

int				get_next_line(int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		rb;
	size_t	llen;
	size_t	blen;

	if (!bak.buff)
		*line = ft_strnew(0);
	else
	{
		bak.buff += bak.index + 1;
		llen = ft_strlenline(bak.buff, '\n');
		blen = ft_strlen(bak.buff);
		*line = ft_strnew(llen);
		strnjoin_realloc(line, bak.buff, llen);
		//ft_strdel(&(bak.buff));
		if (llen != blen)
			return (1);
	}
	while ((rb = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rb] = '\0';
		bak.buff = ft_strdup(buff);
		llen = ft_strlenline(buff, '\n');
		blen = ft_strlen(buff);
		strnjoin_realloc(line, buff, llen);
		if (llen != blen)
		{
			bak.index = llen;
			return (1);
		}
	}
	return (rb);
}

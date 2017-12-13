/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/13 19:32:34 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static t_list	*get_buff(t_list **bufflst, int fd)
{
	t_list			*tmp;

	if (!bufflst || !*bufflst)
	{
		*bufflst = ft_lstnew("", BUFF_SIZE);
		(*bufflst)->content_size = fd;
		return (*bufflst);
	}
	tmp = *bufflst;
	if ((int)tmp->content_size == fd)
		return (tmp);
	while (tmp->next)
	{
		if ((int)tmp->next->content_size == fd)
			return (tmp->next);
		tmp = tmp->next;
	}
	tmp->next = ft_lstnew("", BUFF_SIZE);
	tmp->next->content_size = fd;
	return (tmp->next);
}

static void		read_to_buff(int fd, char *buff, char **line)
{
	int				rb;
	char			*tmp;

	rb = 1;
	while (rb > 0)
	{
		if (!ft_strchr(buff, '\n'))
		{
			rb = read(fd, buff, BUFF_SIZE);
			buff[rb] = '\0';
		}
		else
			rb = 0;
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
}

int				get_next_line(int fd, char **line)
{
	static	t_list	*buffs;
	t_list			*buff;
	char			*tmp;
	int				retval;
	int				nli;

	retval = 0;
	nli = 0;
	if (!line || read(fd, NULL, 0) == -1)
		return (-1);
	buff = get_buff(&buffs, fd);
	*line = ft_strnew(0);
	read_to_buff(fd, buff->content, line);
	while ((*line)[nli] && (*line)[nli] != '\n')
		nli++;
	retval = !(!(*line)[nli]);
	tmp = *line;
	*line = ft_strsub(*line, 0, nli);
	free(tmp);
	tmp = buff->content;
	buff->content = ft_strsub(buff->content, retval ? nli + 1 : nli, ft_strlen(buff->content));
	free(tmp);
	return (retval);
}

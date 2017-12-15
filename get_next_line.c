/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/15 21:55:49 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void		rm_buff(t_list **bufflst, int fd)
{
	t_list			*curr;
	t_list			*prev;

	curr = *bufflst;
	prev = NULL;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				(*bufflst) = curr->next;
			ft_strdel(((char**)&curr->content));
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static t_list	*get_buff(t_list **bufflst, int fd)
{
	t_list			*tmp;

	if (!bufflst)
		return (NULL);
	tmp = *bufflst;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = *bufflst;
	if (!(*bufflst = ft_lstnew("", 1)))
		return (NULL);
	(*bufflst)->content_size = (size_t)fd;
	(*bufflst)->next = tmp;
	return (*bufflst);
}

static int		read_to_buff(int fd, char **stock)
{
	int				rb;
	int				rbt;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	rbt = (ft_strchr(*stock, '\n') == NULL && !ft_strcmp(*stock, "")) ? 0 : 1;
	rb = 1;
	while (rb > 0 && (rbt == 0 || !ft_strchr(*stock, '\n')))
	{
		rb = read(fd, buff, BUFF_SIZE);
		rbt += rb;
		buff[rb] = '\0';
		tmp = *stock;
		if (!(*stock = ft_strjoin(*stock, buff)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
	}
	return (rbt);
}
#include <stdio.h>
int				get_next_line(int fd, char **line)
{
	static	t_list	*buffs;
	t_list			*buff;
	void			*tmp;
	int				retval;
	int				nli;

	retval = 0;
	nli = 0;
	if (!line || !(buff = get_buff(&buffs, fd)))
		return (-1);
	if ((retval = read_to_buff(fd, (char**)(&buff->content))) <= 0)
	{
		*line = ft_strnew(0);
		rm_buff(&buffs, fd);
		return (retval);
	}
	while (((char*)(buff->content))[nli]
			&& ((char*)(buff->content))[nli] != '\n')
		nli++;
	*line = ft_strsub((char*)buff->content, 0, nli);
	if (((char*)(buff->content))[nli] != '\0')
		nli++;
	tmp = buff->content;
	buff->content = ft_strsub((char*)buff->content, nli, \
			ft_strlen(buff->content) - nli);
	free(tmp);
	return (1);
}

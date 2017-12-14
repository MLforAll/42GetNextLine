/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/14 19:58:09 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

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

static void		read_to_buff(int fd, char **stock)
{
	int				rb;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	rb = 1;
	while (rb > 0 && !ft_strchr(*stock, '\n'))
	{
		rb = read(fd, buff, BUFF_SIZE);
		buff[rb] = '\0';
		tmp = *stock;
		if (!(*stock = ft_strjoin(*stock, buff)))
		{
			free(tmp);
			return ;
		}
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
	if (!(buff = get_buff(&buffs, fd)))
		return (-1);
	read_to_buff(fd, (char**)(&buff->content));
	while (((char*)(buff->content))[nli]
			&& ((char*)(buff->content))[nli] != '\n')
		nli++;
	retval = (nli > 0 || ((char*)(buff->content))[nli]);
	*line = ft_strsub(buff->content, 0, nli);
	tmp = buff->content;
	buff->content = ft_strsub(buff->content, retval ? nli + 1 : nli, \
			ft_strlen(buff->content));
	free(tmp);
	return (retval);
}

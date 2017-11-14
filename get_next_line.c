/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:43:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/14 20:07:33 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	reminder;

static int	str_haschar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		rb;
	int		tb;

	(void)line;
	tb = 0;
	while ((rb = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rb] = '\0';
		tb += rb;
		if (tb > reminder)
			reminder = tb;
		if (tb > reminder && str_haschar(buff, '\n'))
			ft_putstr(buff);
	}
	return (1);
}

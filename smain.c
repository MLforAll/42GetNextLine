/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:29:35 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/15 21:36:06 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		rv;
	char	*line;

	if (ac < 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	rv = 1;
	while (rv == 1)
	{
		rv = get_next_line(fd, &line);
		printf("line: [%s] | retval: %i\n", (!line || !*line) ? "empty" : line, rv);
		free(line);
	}
	close(fd);
	return (0);
}

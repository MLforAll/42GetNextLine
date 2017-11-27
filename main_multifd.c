/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:32 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/27 16:21:44 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	show_gnl(int fd, char *fdn)
{
	char	*result;
	int		gnl_retval;

	gnl_retval = get_next_line(fd, &result);
	printf("%s > line: %s | retval = %i\n", fdn, (!*result) ? "(empty)" : result, gnl_retval);
	ft_strdel(&result);
}

int		main(int ac, char **av)
{
	int		fd;
	int		fd2;

	if (ac != 3)
		return (ft_returnmsg("Please provide 2 files!", 2, 1));
	ft_putstr_color("=== Starting test program ===\n\n", WHITECLR);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	if (fd == -1 || fd2 == -1)
		ft_putendl_fd("Err opening the files!", 2);
	show_gnl(fd, "fd1");
	show_gnl(fd2, "fd2");
	show_gnl(fd2, "fd2");
	show_gnl(fd, "fd1");
	show_gnl(fd, "fd1");
	if (close(fd) == -1 || close(fd2) == -1)
		ft_putendl_fd("Err closing the files!", 2);
	ft_putchar('\n');
	ft_putendl_color("=== The test program ran successfully! ===", GREENCLR);
	return (0);
}

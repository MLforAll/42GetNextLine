/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:32 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/13 19:34:08 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		aci;
	int		fd;
	int		gnl_retval;
	int		quit;
	char	*result;

	ft_putstr_color("=== Starting test program ===\n\n", WHITECLR);
	aci = 0;
	quit = 0;
	while (aci < ac)
	{
		gnl_retval = -2;
		if (ac < 2)
		{
			ft_putendl("==> STDIN");
			fd = 0;
		}
		else
		{
			aci += (aci == 0);
			printf("==> File: %s\n", av[aci]);
			fd = open(av[aci], O_RDONLY);
			if (fd == -1)
				ft_putstr_fd("Err opening the file!\n\n", 2);
		}
		while ((gnl_retval == 1 || gnl_retval == -2) && !quit)
		{
			gnl_retval = get_next_line(fd, &result);
			printf("line: (%s) | retval: %i\n", (!result || !*result) ? "empty" : result, gnl_retval);
			if (!ft_strcmp(result, "exit"))
				quit = 1;
			ft_strdel(&result);
		}
		if (gnl_retval == -2)
			ft_putendl_color("!! No line were returned !!", REDCLR);
		if (ac > 1 && fd)
		{
			printf("==> File End: %s\n", av[aci]);
			if (close(fd) == -1)
				ft_putstr_fd("Err closing the file!\n\n", 2);
		}
		ft_putchar('\n');
		aci++;
	}
	ft_putstr_color("=== The test program ran successfully! ===\n", GREENCLR);
	return (0);
}

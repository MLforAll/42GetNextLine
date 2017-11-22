/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:32 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/22 20:48:16 by kdumarai         ###   ########.fr       */
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
	char	*result;
	int		el_stop;

	ft_putstr_color("=== Starting test program ===\n\n", WHITECLR);
	aci = 0;
	while (aci < ac)
	{
		gnl_retval = -2;
		el_stop = 0;
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
		while (gnl_retval > 0 || gnl_retval == -2)
		{
			gnl_retval = get_next_line(fd, &result);
			printf("line: %s | retval = %i\n", (!*result) ? "(empty)" : result, gnl_retval);
			el_stop += (!*result);
			if (el_stop == 10)
			{
				ft_putendl_color("INFINITE LOOP!! YOUR GNL IS NOT WORKING PROPERLY!!", REDCLR);
				break ;
			}
		}
		if (gnl_retval == -2)
			ft_putendl_color("!! No line were returned !!", REDCLR);
		if (ac > 1)
		{
			printf("==> File End: %s\n", av[aci]);
			if (close(fd) == -1)
				ft_putstr_fd("Err closing the file!\n\n", 2);
		}
		if (gnl_retval != -2)
			free(result);
		ft_putchar('\n');
		aci++;
	}
	ft_putstr_color("=== The test program ran successfully! ===\n", GREENCLR);
	return (0);
}

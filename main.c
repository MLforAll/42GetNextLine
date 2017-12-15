/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:32 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/15 03:12:50 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		strchrs(char *str, char *chrs)
{
	int		i;
	int		success;

	while (*str)
	{
		i = 0;
		success = 0;
		while (chrs[i])
			if (*str == chrs[i++])
				success = 1;
		if (!success)
			return (0);
		str++;
	}
	return (1);
}

void	read_files(int *fds, int ac, char *order)
{
	int		aci;
	int		fd;
	int		quit;
	int		gnl_retval;
	char	*result;

	aci = 0;
	quit = 0;
	while (aci < ac)
	{
		fd = fds[aci];
		gnl_retval = 1;
		if (fd > 0 && !order)
		{
			if (aci)
				ft_putchar('\n');
			ft_putstr("==> Reading fd: ");
			ft_putnbr(fd);
			ft_putchar('\n');
		}
		while (gnl_retval == 1 && !quit)
		{
			if (order)
				fd = fds[*(order++) - 49];
			gnl_retval = get_next_line(fd, &result);
			if (fd)
			{
				ft_putstr("\033[1;");
				if (order)
					ft_putnbr(*(order - 1) - 16);
				else
					ft_putnbr(aci + 33);
				ft_putchar('m');
			}
			ft_putstr("line: [");
			ft_putstr((!result || !*result) ? "empty" : result);
			ft_putstr("] | retval: ");
			ft_putnbr(gnl_retval);
			ft_putstr(" | fd: ");
			ft_putnbr(fd);
			ft_putchar('\n');
			ft_putstr("\033[0;39m");
			if ((!ft_strcmp(result, "exit") && fd == 0) || (order && !*order))
				quit = 1;
			ft_strdel(&result);
		}
		aci++;
	}
}

int		main(int ac, char **av)
{
	int		aci;
	int		fds[OPEN_MAX];
	char	*order;

	ft_putstr("\033[1;36m=== Starting test program ===\n\n\033[0;37m");
	aci = 1;
	order = NULL;
	if (ac < 2)
	{
		ft_putstr("==> STDIN");
		fds[0] = 0;
		aci = -1;
	}
	if (strchrs(av[ac - 1], "0123456789"))
	{
		order = av[ac - 1];
		ac--;
	}
	while (aci < ac && aci != -1)
	{
		ft_putstr("==> Opening file at: ");
		ft_putstr(av[aci]);
		ft_putchar('\n');
		if ((fds[aci - 1] = open(av[aci], O_RDONLY)) == -1)
			ft_putstr_fd("\033[1;31mErr opening the file!\n\n\033[0;37m", 2);
		aci++;
	}
	ft_putchar('\n');
	read_files(fds, (ac > 1 && !order) ? ac - 1 : ac, order);
	aci = (aci != -1) ? 1 : aci;
	while (aci < ac && aci != -1)
	{
		ft_putstr("\n==> Closing file at: ");
		ft_putstr(av[aci]);
		if (close(fds[aci - 1]) == -1)
			ft_putstr_fd("\033[1;31mErr closing the file!\n\n\033[0;37m", 2);
		aci++;
	}
	if (aci > 1)
		ft_putchar('\n');
	ft_putstr("\033[1;32m\n=== The test program ran successfully! ===\n\033[0;37m");
	return (0);
}

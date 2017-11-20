/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:32 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/20 20:15:36 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		gnl_retval;
	char	*result;

	ft_putstr_color("=== Starting test program ===\n\n", WHITECLR);
	gnl_retval = -2;
	if (ac < 2)
		fd = 0;
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_returnmsg("Err opening the file!\n", 2, 1));
	}
	while (gnl_retval > 0 || gnl_retval == -2)
	{
		gnl_retval = get_next_line(fd, &result);
		printf("line: %s | retval = %i\n", result, gnl_retval);
	}
	if (gnl_retval == -2)
		ft_putendl_color("No line were returned", REDCLR);
	if (ft_strcmp(av[1], "stdin"))
	{
		if (close(fd) == -1)
			return (ft_returnmsg("Err closing the file!\n", 2, 1));
	}
	ft_putstr_color("\n=== The test program ran successfully! ===\n", GREENCLR);
	return (0);
}

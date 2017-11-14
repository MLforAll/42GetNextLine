/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:32 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/14 20:08:22 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*result;
	
	ft_putendl_color("Starting test program", BLUECLR);
	if (ac < 2)
		return(ft_returnmsg("Specify a file!", 2, 1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return(ft_returnmsg("Err opening the file!", 2, 1));
	while (get_next_line)
	{
		get_next_line(fd, &result);
		printf("line: %s\n", result);
	}
	if (close(fd) == -1)
		return(ft_returnmsg("Err closing the file!", 2, 1));
	ft_putendl_color("The test program ran successfully!", GREENCLR);
	return (0);
}

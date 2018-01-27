/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:44:11 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/15 18:06:05 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		gusage(void)
{
	printf("USAGE:\n");
	printf("\t1. file\n");
	printf("\t2. length\n");
	printf("\t3. nb of lines\n");
	printf("\t4. terminate with \\n\n");
	return (1);
}

int		gerr(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	int		len;
	int		lines;
	char	c;

	if (ac < 2)
		return (gusage());
	i = 0;
	len = atoi(av[2]);
	lines = atoi(av[3]);
	if (access(av[1], F_OK) != -1)
		return (gerr("File already there!"));
	if ((fd = open(av[1], O_WRONLY | O_CREAT, 0644)) == -1)
		return (gerr("Couldn't open file!"));
	while (i < len)
	{
		c = (i % (len / lines) == 0 && i > 0) ? '\n' : arc4random_uniform(95) + 32;
		write(fd, &c, 1);
		i++;
	}
	if (ac > 4 && (!strcmp(av[4], "yes") || atoi(av[4]) == 1))
		write(fd, "\n", 1);
	if (close(fd) == -1)
		printf("Couldn't close file!\n");
	printf("File created at: %s\n", av[1]);
	return (0);
}

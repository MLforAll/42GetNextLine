/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:41:33 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/20 15:27:43 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include "Libft/libft.h"
# define BUFF_SIZE	128

typedef struct	s_backup
{
	char	*buff;
	size_t	index;
}				t_backup;

int		get_next_line(const int fd, char **line);

#endif

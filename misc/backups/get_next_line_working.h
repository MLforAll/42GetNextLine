/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:41:33 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/12 17:20:09 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "Libft/libft.h"
# define BUFF_SIZE	32

typedef struct		s_buff
{
	char			buff[BUFF_SIZE + 1];
	int				fd;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif

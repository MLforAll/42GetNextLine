/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:15:36 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/05 17:07:45 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Get_Next_Line/get_next_line.h"
#include "../Libft/libft.h"
#include <stdlib.h>

int		main(void)
{
	char	*result;

	while (1)
	{
		ft_putstr_color("kelian-sh $> ", CYANCLR);
		if (get_next_line(0, &result) < 1)
			return (ft_returnmsg("err!", 2, 1));
		if (!ft_strcmp(result, "exit"))
			break ;
		system(result);
		ft_strdel(&result);
	}
	return (0);
}

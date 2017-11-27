/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr_lenline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:30:06 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/27 15:38:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

static size_t	ft_strlenline(char *str)
{
	size_t	ret;

	ret = 0;
	while (*str)
	{
		if (*str == '\n')
			break ;
		ret++;
		str++;
	}
	return (ret);
}

int				main(void)
{
	char	str[50] = "some string with \"cases\"\n2nd line";
	printf("llen = %lu | trusty = %li\n", strchr((const char*)str, '\n') == NULL ? strlen(str) : strchr((const char*)str, '\n') - str, ft_strlenline(str));
	return (0);
}

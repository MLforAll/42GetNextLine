/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_ex_login.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:03:25 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/08 17:36:54 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../Get_Next_Line/get_next_line.h"

char	*get_login(char *fn, char *ln)
{
	int		i;
	int		p;
	int		cf;
	int		cl;
	char	*ret;

	i = -1;
	p = 0;
	ret = ft_strnew(8);
	cf = ft_strlen(ln);
	cf = (cf < 7) ? 8 - cf : 1;
	cl = 8 - cf;
	while (++i < cf)
		ret[i] = ft_tolower(fn[i]);
	while (p < cl)
		ret[i++] = ft_tolower(ln[p++]);
	return (ret);
}

int		main(void)
{
	char	*firstname;
	char	*lastname;
	char	*login;

	ft_putstr("Enter your first name: ");
	get_next_line(0, &firstname);
	ft_putstr("Enter your last name: ");
	get_next_line(0, &lastname);
	login = get_login(firstname, lastname);
	ft_putstr("Your 42 login is: ");
	ft_putendl(login);
	ft_strdel(&login);
	ft_strdel(&firstname);
	ft_strdel(&lastname);
	return (0);
}

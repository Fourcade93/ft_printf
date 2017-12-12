/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:31:35 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 16:43:57 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

int	ft_check_c(char c)
{
	char	*conv;
	char	*flags;
	int		ret;

	conv = ">sSpdDioOuUxXcC%";
	flags = ">lljzhh#+- ";
	if (c > 47 && c < 58)
		return (11);
	if (ft_findchr(conv, c))
		return (12);
	if ((ret = ft_findchr(flags, c)))
		return (ret);
	return (0);
}

int	ft_get_num(const char *av, int *i, t_flags *flags)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	(av[*i] == '-') ? sign = -1 : sign;
	(av[*i] == '-' || av[*i] == '.') ? *i += 1 : *i;
	while (av[*i] && ((av[*i] > 47 && av[*i] < 58) || av[*i] == '+' ||
	av[*i] == '#'))
	{
		if (ft_check_c(av[*i]) == 11)
			res = res * 10 + (av[*i] - '0');
		(av[*i] == '+') ? ((*flags).flag |= 1UL << 8) : (*flags).flag;
		(av[*i] == '#') ? ((*flags).flag |= 1UL << 7) : (*flags).flag;
		*i += 1;
	}
	*i -= 1;
	return (res * sign);
}

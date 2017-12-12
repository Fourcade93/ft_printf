/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recieve_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:57:17 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 17:18:04 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		back_i_help(const char *av, int *i, t_flags flags, int *num_width)
{
	int	space;

	space = 0;
	while (av[*i] != '%')
		*i -= 1;
	*i += 1;
	if (av[*i] == ' ')
		*i += 1;
	if (av[*i] == '0')
	{
		*num_width = ft_get_num(av, &(*i), &flags);
		*i += 1;
	}
	if (ft_check_c(av[*i]) == 11 ||
		(av[*i] == '-' && ft_check_c(av[(*i) + 1]) == 11))
	{
		space = ft_get_num(av, &(*i), &flags);
		*i += 1;
	}
	return (space);
}

int		back_i(const char *av, int *i, t_flags flags)
{
	int	space;
	int	j;
	int	num_width;

	space = 0;
	j = 0;
	num_width = 0;
	space = back_i_help(av, &(*i), flags, &num_width);
	while (space-- > 1 && ++j)
		write(1, " ", 1);
	while (num_width-- > 1 && ++j)
		write(1, "0", 1);
	if (av[*i] && av[*i] != '.' && ft_check_c(av[*i]) == 0)
	{
		j++;
		write(1, &av[*i], 1);
	}
	(!av[*i] || av[*i] == '%') ? *i -= 1 : *i;
	while (++space < -1 && ++j)
		write(1, " ", 1);
	return ((j) ? j : 0);
}

int		ft_printf(const char *av, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, av);
	while (av[i])
	{
		if (av[i] != '%')
		{
			count++;
			write(1, &(av[i]), 1);
		}
		else
			count += get_spec(av, &i, args);
		(av[i]) ? i++ : i;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recieve_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:57:17 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/05 21:30:08 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//delete_me!!!
#include <stdarg.h>
#include "ft_printf.h"
#include "func_struct.h"

int		ft_findchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

int		ft_check_c(char c)
{
	char	*conv;

	conv = "sSpdDioOuUxXcC%";
	if (c == '+')
		return (8);
	if (c == '#')
		return (7);
	if (c == 'z')
		return (6);
	if (c == 'j')
		return (5);
	if (c > 47 && c < 58)
		return (2);
	if (ft_findchr(conv, c))
		return (1);
	return (0);
}

int		ft_get_num(const char *av, int *i, t_flags *flags)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	(av[*i] == '-') ? sign = -1 : sign;
	(av[*i] == '-' || av[*i] == '.') ? *i += 1 : *i;
	while (av[*i] && ((av[*i] > 47 && av[*i] < 58) || av[*i] == '+'))
	{
		if (ft_check_c(av[*i]) == 2)
			res = res * 10 + (av[*i] - '0');
		(av[*i] == '+') ? ((*flags).flag |= 1UL << 8) : (*flags).flag;
		*i += 1;
	}
	*i -= 1;
	return (res * sign);
}

int		print_arg(char c, va_list args, t_flags flags)
{
	int		j;
	int		i;
	void	*var;

	if ((flags.flag >> 10) & 1U && flags.min_width > 0)
		flags.min_width = flags.min_width - 1;
	else if ((flags.flag >> 10) & 1U && flags.min_width < 0)
		flags.min_width = flags.min_width + 1;
	if (c == '%')
		return (ft_put_char('%', flags));
	var = va_arg(args, void *);
	if ((flags.flag >> 8) & 1U || c == 'c' || c == 'C' ||
	((int)var < 0 && (c == 'd' || c == 'D' || c == 'i')))
		flags.flag &= ~(1UL << 10);
	i = 0;
	while (++i < 7 && !((flags.flag >> i) & 1U))
		;
	(i == 7) ? i = 0 : i;
	j = 0;
	while ((g_funcs[i][j]).spec != c)
		j++;
	(c == 's') ? flags.flag |= 1UL << 11 : flags.flag;
	if ((c == 'X' || c == 'x') && (flags.flag >> 7) & 1U)
		flags.flag |= 1UL << 12;
	if ((c == 'O' || c == 'o') && (flags.flag >> 7) & 1U)
		flags.flag |= 1UL << 13;
	return (((flags.flag >> 10) & 1U) + ((g_funcs[i][j]).func)(var, flags));
}

int		get_spec(const char *av, int *i, va_list args)
{
	t_flags	flags;
	int		check;

	flags.flag = 0;
	flags.min_width = 0;
	flags.num_width = 0;
	flags.dot_width = 0;
	*i += 1;
	while (av[*i] && !(ft_check_c(av[*i]) == 1))
	{
		(av[*i] == ' ') ? (flags.flag |= 1UL << 10) : flags.flag;
		if (av[*i] == '0')
			flags.num_width = ft_get_num(av, &(*i), &flags);
		else if (av[*i] == '.')
			flags.dot_width = ft_get_num(av, &(*i), &flags);
		else if (ft_check_c(av[*i]) == 2 || av[*i] == '-')
			flags.min_width = ft_get_num(av, &(*i), &flags);
		else if (av[*i] == 'l')
		{
			(av[(*i) + 1] == 'l') ? (flags.flag |= 1UL << 2) : (flags.flag |= 1UL << 1);
			(av[(*i) + 1] == 'l') ? *i += 1 : *i;
		}
		else if (av[*i] == 'h')
		{
			(av[(*i) + 1] == 'h') ? (flags.flag |= 1UL << 3) : (flags.flag |= 1UL << 4);
			(av[(*i) + 1] == 'h') ? *i += 1 : *i;
		}
		else if ((check = ft_check_c(av[*i])) > 4 && check < 9)
			flags.flag |= 1UL << check;
		(av[*i]) ? *i += 1 : *i;
	}
	return (print_arg(av[*i], args, flags));
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
		i++;
	}
	return (count);
}

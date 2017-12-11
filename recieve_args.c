/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recieve_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:57:17 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/11 20:20:48 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//delete_me!!!
#include <stdarg.h>
#include "ft_printf.h"
#include "func_struct.h"

int		ft_findchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

int		ft_check_c(char c)
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

int		ft_get_num(const char *av, int *i, t_flags *flags)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	(av[*i] == '-') ? sign = -1 : sign;
	(av[*i] == '-' || av[*i] == '.') ? *i += 1 : *i;
	while (av[*i] && ((av[*i] > 47 && av[*i] < 58) || av[*i] == '+' || av[*i] == '#'))
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

int		print_arg(char c, va_list args, t_flags flags)
{
	int		j;
	int		i;
	void	*var;

	if (!((flags.flag >> PLUS) & 1U) && (flags.flag >> SPACE) & 1U && flags.min_width > 0)
		flags.min_width = flags.min_width - 1;
	else if (!((flags.flag >> PLUS) & 1U) && (flags.flag >> SPACE) & 1U && flags.min_width < 0)
		flags.min_width = flags.min_width + 1;
	if (c == '%')
		return (ft_put_char('%', flags));
	var = va_arg(args, void *);
	if ((flags.flag >> 8) & 1U || !(c == 'd' || c == 'D' || c == 'i') ||
	((int)var < 0 && (c == 'd' || c == 'D' || c == 'i')))
		flags.flag &= ~(1UL << SPACE);
	i = 0;
	while (++i < 7 && !((flags.flag >> i) & 1U))
		;
	(i == 7) ? i = 0 : i;
	j = 0;
	while ((g_funcs[i][j]).spec != c)
		j++;
	(c == 's') ? flags.flag |= 1UL << 11 : flags.flag;
	(c == 'U') ? flags.flag |= 1UL << 14 : flags.flag;
	(c == 'D') ? flags.flag |= 1UL << 15 : flags.flag;
	(c == 'O') ? flags.flag |= 1UL << 16 : flags.flag;
	if ((c == 'X' || c == 'x') && (flags.flag >> 7) & 1U)
		flags.flag |= 1UL << 12;
	if ((c == 'O' || c == 'o') && (flags.flag >> 7) & 1U)
		flags.flag |= 1UL << 13;
	return (((g_funcs[i][j]).func)(var, flags));
}

int		back_i(const char *av, int *i, t_flags flags)
{
	int	space;
	int	j;
	int	num_width;

	space = 0;
	j = 0;
	num_width = 0;
	while (av[*i] != '%')
		*i -= 1;
	*i += 1;
	if (av[*i] == ' ')
		*i += 1;
	if (av[*i] == '0')
	{
		num_width = ft_get_num(av, &(*i), &flags);
		*i += 1;
	}
	if (ft_check_c(av[*i]) == 11 ||
	(av[*i] == '-' && ft_check_c(av[(*i) + 1]) == 11))
	{
		space = ft_get_num(av, &(*i), &flags);
		*i += 1;
	}
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

int		get_spec(const char *av, int *i, va_list args)
{
	t_flags	flags;
	int		check;

	flags.flag = 0;
	flags.min_width = 0;
	flags.num_width = 0;
	flags.dot_width = -1;
	*i += 1;
	if (!av[*i])
		return (0);
	while (av[*i] && !(ft_check_c(av[*i]) == 12))
	{
		if (av[*i] == '0' && !((flags.flag >> MINUS) & 1U))
			flags.num_width = ft_get_num(av, &(*i), &flags);
		else if (av[*i] == '.')
			flags.dot_width = ft_get_num(av, &(*i), &flags);
		else if (ft_check_c(av[*i]) == 11)
			flags.min_width = ft_get_num(av, &(*i), &flags);
		else if (av[*i] == 'l')
		{
			(av[(*i) + 1] == 'l') ? (flags.flag |= 1UL << LL) : (flags.flag |= 1UL << L);
			(av[(*i) + 1] == 'l') ? *i += 1 : *i;
		}
		else if (av[*i] == 'h')
		{
			(av[(*i) + 1] == 'h') ? (flags.flag |= 1UL << HH) : (flags.flag |= 1UL << H);
			(av[(*i) + 1] == 'h') ? *i += 1 : *i;
		}
		else if ((check = ft_check_c(av[*i])) > 1 && check < 11)
			flags.flag |= 1UL << check;
		else if (ft_check_c(av[*i]) != 12)
			return (back_i(av, &(*i), flags));
		(av[*i]) ? *i += 1 : *i;
	}
	((flags.flag >> MINUS) & 1U) ? flags.min_width = -flags.min_width : 1;
	if ((flags.flag >> SPACE) & 1U && flags.num_width > 0)
		flags.num_width -= 1;
	return ((av[*i]) ? print_arg(av[*i], args, flags) : 0);
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

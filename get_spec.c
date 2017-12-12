/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:33:34 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 16:51:20 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "func_struct.h"

void	print_arg_help(char c, t_flags *flags, int *i, int *j)
{
	while (*i < 7 && !(((*flags).flag >> *i) & 1U))
		*i += 1;
	(*i == 7) ? *i = 0 : *i;
	while ((g_funcs[*i][*j]).spec != c)
		*j += 1;
	(c == 's') ? (*flags).flag |= 1UL << STR : (*flags).flag;
	(c == 'U') ? (*flags).flag |= 1UL << UI : (*flags).flag;
	(c == 'D') ? (*flags).flag |= 1UL << DEC : (*flags).flag;
	(c == 'O') ? (*flags).flag |= 1UL << UOCT : (*flags).flag;
	if ((c == 'X' || c == 'x') && ((*flags).flag >> HASH) & 1U)
		(*flags).flag |= 1UL << OX_X;
	if ((c == 'O' || c == 'o') && ((*flags).flag >> HASH) & 1U)
		(*flags).flag |= 1UL << O0;
}

int		print_arg(char c, va_list args, t_flags flags)
{
	int		j;
	int		i;
	void	*var;

	if (!((flags.flag >> PLUS) & 1U) && (flags.flag >> SPACE) & 1U
	&& flags.min_width > 0)
		flags.min_width = flags.min_width - 1;
	else if (!((flags.flag >> PLUS) & 1U) && (flags.flag >> SPACE) & 1U
	&& flags.min_width < 0)
		flags.min_width = flags.min_width + 1;
	if (c == '%')
		return (ft_put_char('%', flags));
	var = va_arg(args, void *);
	if ((flags.flag >> PLUS) & 1U || !(c == 'd' || c == 'D' || c == 'i') ||
		((int)var < 0 && (c == 'd' || c == 'D' || c == 'i')))
		flags.flag &= ~(1UL << SPACE);
	i = 1;
	j = 0;
	print_arg_help(c, &flags, &i, &j);
	return (((g_funcs[i][j]).func)(var, flags));
}

int		get_spec_help(const char *av, int *i, t_flags *flags)
{
	int	check;

	if (av[*i] == '0' && !(((*flags).flag >> MINUS) & 1U))
		(*flags).num_width = ft_get_num(av, &(*i), &(*flags));
	else if (av[*i] == '.')
		(*flags).dot_width = ft_get_num(av, &(*i), &(*flags));
	else if (ft_check_c(av[*i]) == 11)
		(*flags).min_width = ft_get_num(av, &(*i), &(*flags));
	else if (av[*i] == 'l')
	{
		(av[(*i) + 1] == 'l') ? ((*flags).flag |= 1UL << LL) :
		((*flags).flag |= 1UL << L);
		(av[(*i) + 1] == 'l') ? *i += 1 : *i;
	}
	else if (av[*i] == 'h')
	{
		(av[(*i) + 1] == 'h') ? ((*flags).flag |= 1UL << HH) :
		((*flags).flag |= 1UL << H);
		(av[(*i) + 1] == 'h') ? *i += 1 : *i;
	}
	else if ((check = ft_check_c(av[*i])) > 1 && check < 11)
		(*flags).flag |= 1UL << check;
	else if (ft_check_c(av[*i]) != 12)
		return (0);
	return (1);
}

int		get_spec(const char *av, int *i, va_list args)
{
	t_flags flags;

	flags.flag = 0;
	flags.min_width = 0;
	flags.num_width = 0;
	flags.dot_width = -1;
	*i += 1;
	if (!av[*i])
		return (0);
	while (av[*i] && !(ft_check_c(av[*i]) == 12))
	{
		if (!get_spec_help(av, &(*i), &flags))
			return (back_i(av, &(*i), flags));
		(av[*i]) ? *i += 1 : *i;
	}
	((flags.flag >> MINUS) & 1U) ? flags.min_width = -flags.min_width : 1;
	if ((flags.flag >> SPACE) & 1U && flags.num_width > 0)
		flags.num_width -= 1;
	return ((av[*i]) ? print_arg(av[*i], args, flags) : 0);
}

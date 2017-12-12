/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:19:12 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 17:31:27 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_uint_len(size_t n, size_t base)
{
	int i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

int		get_len(int64_t n, int base, int *stop, t_flags flags)
{
	int			len;
	int64_t		num;

	len = 1;
	num = n;
	if (base == 10 && num < 0)
		num = -num;
	while ((num /= base))
		len++;
	(len < flags.dot_width) ? len = flags.dot_width : len;
	if (flags.dot_width != -1 && flags.dot_width < flags.num_width
	&& len < flags.num_width)
		*stop = flags.num_width - len;
	((flags.flag >> 8) & 1U || n < 0) ? len += 1 : len;
	(((flags.flag >> 8) & 1U || n < 0) && *stop != -1) ? *stop -= 1 : *stop;
	(len < flags.num_width) ? len = flags.num_width : len;
	return (len);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	if (str)
		while (*str++)
			len++;
	return (len);
}

int		ft_arrlen(int *arr)
{
	int	len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

int		ft_putpoint(long long n, t_flags flags)
{
	flags.flag |= 1UL << 17;
	return (ft_uint_itoa_base(n, 16, 1, flags));
}

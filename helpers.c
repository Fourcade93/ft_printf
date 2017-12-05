/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:19:12 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/05 16:21:27 by fmallaba         ###   ########.fr       */
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

int		get_len(int64_t n, int base)
{
	int i;

	i = 1;
	if (base == 10 && n < 0)
		n = -n;
	while ((n /= base))
		i++;
	return (i);
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
	write(1, "0x", 2);
	return (2 + ft_itoa_base(n, 16, 1, flags));
}

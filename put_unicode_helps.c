/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unicode_helps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:59:56 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 16:52:22 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_bits(unsigned int n)
{
	int	count;

	count = 31;
	while (count >= 0 && !((n >> count) & 1U))
		count--;
	return (count + 1);
}

int	print_four_byte(unsigned int n)
{
	unsigned int	mask;
	unsigned char	c[4];
	unsigned char	out;

	mask = 4034953344;
	c[3] = (n << 26) >> 26;
	c[2] = ((n >> 6) << 26) >> 26;
	c[1] = ((n >> 12) << 26) >> 26;
	c[0] = ((n >> 18) << 29) >> 29;
	out = c[0] | (mask >> 24);
	write(1, &out, 1);
	out = c[1] | ((mask << 8) >> 24);
	write(1, &out, 1);
	out = c[2] | ((mask << 16) >> 24);
	write(1, &out, 1);
	out = c[3] | ((mask << 24) >> 24);
	write(1, &out, 1);
	return (4);
}

int	print_three_byte(unsigned int n)
{
	unsigned int	mask;
	unsigned char	c[3];
	unsigned char	out;

	mask = 14712960;
	c[2] = (n << 26) >> 26;
	c[1] = ((n >> 6) << 26) >> 26;
	c[0] = ((n >> 12) << 26) >> 26;
	out = c[0] | (mask >> 16);
	write(1, &out, 1);
	out = c[1] | ((mask << 16) >> 24);
	write(1, &out, 1);
	out = c[2] | ((mask << 24) >> 24);
	write(1, &out, 1);
	return (3);
}

int	print_two_byte(unsigned int n)
{
	unsigned int	mask;
	unsigned char	c1;
	unsigned char	c2;
	unsigned char	out;

	mask = 49280;
	c2 = (n << 26) >> 26;
	c1 = ((n >> 6) << 27) >> 27;
	out = c1 | (mask >> 8);
	write(1, &out, 1);
	out = c2 | mask;
	write(1, &out, 1);
	return (2);
}

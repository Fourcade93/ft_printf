/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_char_calls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:22:07 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/04 18:43:17 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uchar(unsigned char c, t_flags flags)
{
	int	space;

	space = 0;
	if (flags.min_width > 0)
	{
		space = flags.min_width - 1;
		while (space-- > 0)
			write(1, " ", 1);
	}
	write(1, &c, 1);
	if (flags.min_width < 0)
	{
		flags.min_width = -flags.min_width;
		space = flags.min_width - 1;
		while (space-- > 0)
			write(1, " ", 1);
	}
	return (1 + ((flags.min_width - 1 > 0) ? flags.min_width - 1 : 0));
}

int	ft_char_oct_itoa(unsigned int n, t_flags flags)
{
	unsigned char	c;

	c = n;
	return (ft_put_uchar(c, flags));
}

int	ft_char_dec_itoa(int n, t_flags flags)
{
	return (ft_put_char(n, flags));
}

int	ft_char_uphex_itoa(unsigned int n, t_flags flags)
{
	unsigned char	c;

	c = n;
	return (ft_put_uchar(c, flags));
}

int	ft_char_lowhex_itoa(unsigned int n, t_flags flags)
{
	unsigned char	c;

	c = n;
	return (ft_put_uchar(c, flags));
}

int	ft_char_uint_itoa(unsigned int n, t_flags flags)
{
	unsigned char	c;

	c = n;
	return (ft_put_uchar(c, flags));
}

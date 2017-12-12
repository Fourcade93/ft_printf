/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_char_calls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:22:07 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 16:50:56 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_oct_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	if (!(((flags.flag >> 16) & 1U)))
	{
		c = n;
		n = c;
	}
	return (ft_uint_itoa_base(n, 8, 1, flags));
}

int	ft_char_dec_itoa(int n, t_flags flags)
{
	char c;

	if (!(((flags.flag >> 15) & 1U)))
	{
		c = n;
		n = c;
	}
	return (ft_itoa_base(n, 10, 1, flags));
}

int	ft_char_uphex_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	c = n;
	return (ft_uint_itoa_base(c, 16, 0, flags));
}

int	ft_char_lowhex_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	c = n;
	return (ft_uint_itoa_base(c, 16, 1, flags));
}

int	ft_char_uint_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	if (!(((flags.flag >> 14) & 1U)))
	{
		c = n;
		n = c;
	}
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

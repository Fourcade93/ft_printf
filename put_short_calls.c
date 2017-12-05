/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_short_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:23:39 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/04 17:16:55 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_short_oct_itoa(unsigned int n, t_flags flags)
{
	unsigned short int	s;

	s = n;
	return (ft_itoa_base(s, 8, 1, flags));
}

int	ft_short_dec_itoa(int n, t_flags flags)
{
	short int	s;

	s = n;
	return (ft_itoa_base(s, 10, 1, flags));
}

int	ft_short_uphex_itoa(unsigned int n, t_flags flags)
{
	unsigned short int	s;

	s = n;
	return (ft_itoa_base(s, 16, 0, flags));
}

int	ft_short_lowhex_itoa(unsigned int n, t_flags flags)
{
	unsigned short int	s;

	s = n;
	return (ft_itoa_base(s, 16, 1, flags));
}

int	ft_short_uint_itoa(unsigned int n, t_flags flags)
{
	unsigned short int	s;

	s = n;
	return (ft_itoa_base(s, 10, 1, flags));
}

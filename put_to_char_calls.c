/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_char_calls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:22:07 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/05 21:33:37 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //delete_me!!!

int	ft_char_oct_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	c = n;
	return (ft_uint_itoa_base(c, 10, 1, flags));
}

int	ft_char_dec_itoa(int n, t_flags flags)
{
	char	c;

	c = n;
	return (ft_itoa_base(c, 10, 1, flags));
}

int	ft_char_uphex_itoa(unsigned int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

int	ft_char_lowhex_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	c = n;
	return (ft_uint_itoa_base(c, 10, 1, flags));
}

int	ft_char_uint_itoa(unsigned int n, t_flags flags)
{
	unsigned char c;

	c = n;
	return (ft_uint_itoa_base(c, 10, 1, flags));
}

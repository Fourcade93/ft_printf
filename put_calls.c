/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_calls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:17:24 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/06 14:40:11 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_oct_itoa(unsigned int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 8, 1, flags));
}

int	ft_dec_itoa(int n, t_flags flags)
{
	return (ft_itoa_base(n, 10, 1, flags));
}

int	ft_uphex_itoa(unsigned int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 0, flags));
}

int	ft_lowhex_itoa(unsigned int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 1, flags));
}

int	ft_uint_itoa(unsigned int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

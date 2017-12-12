/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_long_calls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:12:28 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/04 17:16:42 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_l_oct_itoa(unsigned long int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 8, 1, flags));
}

int	ft_l_dec_itoa(long int n, t_flags flags)
{
	return (ft_itoa_base(n, 10, 1, flags));
}

int	ft_l_uphex_itoa(unsigned long int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 0, flags));
}

int	ft_l_lowhex_itoa(unsigned long int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 1, flags));
}

int	ft_l_uint_itoa(unsigned long int n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

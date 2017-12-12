/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_z_calls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:27:35 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/06 20:17:44 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_z_oct_itoa(size_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 8, 1, flags));
}

int	ft_z_dec_itoa(size_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

int	ft_z_uphex_itoa(size_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 0, flags));
}

int	ft_z_lowhex_itoa(size_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 1, flags));
}

int	ft_z_uint_itoa(size_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

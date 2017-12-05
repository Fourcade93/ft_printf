/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_max_calls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:25:24 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/04 17:16:59 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max_oct_itoa(uintmax_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 8, 1, flags));
}

int	ft_max_dec_itoa(intmax_t n, t_flags flags)
{
	return (ft_itoa_base(n, 10, 1, flags));
}

int	ft_max_uphex_itoa(uintmax_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 0, flags));
}

int	ft_max_lowhex_itoa(uintmax_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 16, 1, flags));
}

int	ft_max_uint_itoa(uintmax_t n, t_flags flags)
{
	return (ft_uint_itoa_base(n, 10, 1, flags));
}

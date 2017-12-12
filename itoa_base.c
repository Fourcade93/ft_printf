/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:04:35 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 17:30:01 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uint_itoa_base_help(size_t n, t_flags *flags, int *len)
{
	char	*str;

	(((*flags).flag >> O0) & 1U && n > 0) ? *len += 1 : *len;
	(*len < (*flags).dot_width) ? *len = (*flags).dot_width : *len;
	(((*flags).flag >> P) & 1U) ? *len += 2 : *len;
	(((*flags).flag >> OX_X) & 1U && n > 0) ? *len += 2 :
	((*flags).flag &= ~(1UL << OX_X));
	(*len < (*flags).num_width) ? *len = (*flags).num_width : *len;
	str = (char *)malloc(sizeof(char) * (*len + 1));
	str[*len] = '\0';
	return (str);
}

int		ft_uint_itoa_base(size_t n, size_t base, int up_low, t_flags flags)
{
	char	*arr;
	char	*str;
	int		len;

	if (up_low)
		arr = "0123456789abcdefx";
	else
		arr = "0123456789ABCDEFX";
	len = get_uint_len(n, base);
	str = ft_uint_itoa_base_help(n, &flags, &len);
	str[--len] = arr[n % base];
	while (len)
	{
		n /= base;
		str[--len] = arr[n % base];
	}
	if ((flags.flag >> OX_X) & 1U || (flags.flag >> P) & 1U)
	{
		str[0] = '0';
		str[1] = arr[16];
	}
	len = ft_put_str(str, flags);
	free(str);
	return (len);
}

char	*ft_itoa_base_help(int64_t n, int base, t_flags flags, char *arr)
{
	int		stop;
	int		sign;
	int		len;
	char	*str;

	sign = 0;
	stop = -1;
	len = get_len(n, base, &stop, flags);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	(base == 10 && n < 0) ? sign = 1 : sign;
	(base == 10 && n < 0) ? n = -n : n;
	while (len > ((stop != -1) ? stop : 0))
	{
		str[--len] = arr[n % base];
		n /= base;
	}
	(sign) ? (str[len] = '-') : sign;
	((flags.flag >> 8) & 1U && !sign) ? (str[len] = '+') : sign;
	while (len--)
		str[len] = ' ';
	return (str);
}

int		ft_itoa_base(int64_t n, int base, int up_low, t_flags flags)
{
	char	*arr;
	char	*str;
	int		len;

	if (n == INT64_MIN && base == 10)
		return (ft_put_str("-9223372036854775808", flags));
	if (up_low)
		arr = "0123456789abcdef";
	else
		arr = "0123456789ABCDEF";
	str = ft_itoa_base_help(n, base, flags, arr);
	len = ft_put_str(str, flags);
	free(str);
	return (len);
}

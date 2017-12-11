/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:17:35 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/11 19:05:12 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//delete_me!!!

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
	((flags.flag >> 13) & 1U && n > 0) ? len += 1 : len;
	(len < flags.dot_width) ? len = flags.dot_width : len;
	((flags.flag >> 17) & 1U) ? len += 2 : len;
	((flags.flag >> 12) & 1U && n > 0) ? len += 2 : (flags.flag &= ~(1UL << 12));
	(len < flags.num_width) ? len = flags.num_width : len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	str[--len] = arr[n % base];
	while (len)
	{
		n /= base;
		str[--len] = arr[n % base];
	}
	if ((flags.flag >> 12) & 1U || (flags.flag >> 17) & 1U)
	{
		str[0] = '0';
		str[1] = arr[16];
	}
	len = ft_putstr(str, flags);
	free(str);
	return (len);
}

int		ft_itoa_base(int64_t n, int base, int up_low, t_flags flags)
{
	char	*arr;
	char	*str;
	int		len;
	int		sign;
	int		stop;

	if (n == INT64_MIN && base == 10)
		return (ft_putstr("-9223372036854775808", flags));
	if (up_low)
		arr = "0123456789abcdef";
	else
		arr = "0123456789ABCDEF";
	sign = 0;
	stop = -1;
	len = get_len(n, base);
	(len < flags.dot_width) ? len = flags.dot_width : len;
	if (flags.dot_width != -1 && flags.dot_width < flags.num_width && len < flags.num_width)
		stop = flags.num_width - len;
	((flags.flag >> 8) & 1U || n < 0) ? len += 1 : len;
	(((flags.flag >> 8) & 1U || n < 0) && stop != -1) ? stop -= 1 : stop;
	(len < flags.num_width) ? len = flags.num_width : len;
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
	stop = ft_putstr(str, flags);
	free(str);
	return (stop);
}

int		ft_putstr(char *str, t_flags flags)
{
	int	len;
	int	space;
	int	zero;

	len = 0;
	space = 0;
	zero = 0;
	if (str == NULL)
		len = 6;
	else
		len = ft_strlen(str);
	if (((flags.flag >> 11) & 1U) && flags.dot_width != -1 && flags.dot_width < len)
		len = flags.dot_width;
	if (ft_strlen(str) == 1 && *str == '0' && !flags.dot_width && !((flags.flag >> 13) & 1U))
		len = 0;
	(flags.min_width > 0) ? space = flags.min_width - len : space;
	if ((flags.flag >> 10) & 1U)
		write (1, " ", 1);
	while (space-- > 0)
		write(1, " ", 1);
	while (((flags.flag >> 11) & 1U) && zero < flags.num_width - len)
	{
		write(1, "0", 1);
		zero++;
	}
	if ((flags.flag >> 17) & 1U && ft_strlen(str) == 3 && !flags.dot_width)
		len -= 1;
	if (str == NULL)
		write(1, "(null)", len);
	else if (!(ft_strlen(str) == 1 && *str == '0' && !flags.dot_width && !((flags.flag >> 13) & 1U)))
		write(1, str, len);
	(flags.min_width < 0) ? space = (flags.min_width = -(flags.min_width)) - len : space;
	while (space-- > 0)
		write(1, " ", 1);
	return (len + ((flags.min_width - len > 0) ? flags.min_width - len : 0) +
			zero + ((flags.flag >> 10) & 1U));
}

int		ft_put_char(int n, t_flags flags)
{
	int space;
	int	zero;

	space = 0;
	zero = 0;
	(flags.min_width > 0) ? space = flags.min_width - 1 : space;
	while (space-- > 0)
		write(1, " ", 1);
	while (zero < flags.num_width - 1)
	{
		write(1, "0", 1);
		zero++;
	}
	write(1, &n, 1);
	(flags.min_width < 0) ? space = (flags.min_width = -(flags.min_width)) - 1 : space;
	while (space-- > 0)
		write(1, " ", 1);
	return (1 + ((flags.min_width - 1 > 0) ? flags.min_width - 1 : 0) + zero);
}

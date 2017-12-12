/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:56:27 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 17:16:46 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_of_w_str(unsigned int *arr, int max)
{
	int	len;
	int	size;

	len = 0;
	while (arr && *arr)
	{
		size = count_bits(*arr);
		if (size < 8 && (max == -1 || max >= len + 1))
			len++;
		else if (size < 12 && (max == -1 || max >= len + 2))
			len += 2;
		else if (size < 17 && (max == -1 || max >= len + 3))
			len += 3;
		else if (max == -1 || max >= len + 4)
			len += 4;
		else
			return (len);
		arr++;
	}
	return (len);
}

void	print_w_str(unsigned int *arr, int *count, int len)
{
	int	size;

	while (arr && *arr)
	{
		size = count_bits(*arr);
		if (size < 8 && len - (*count + 1) >= 0)
		{
			*count += 1;
			write(1, &(*arr), 1);
		}
		else if (size < 12 && len - (*count + 2) >= 0)
			*count += print_two_byte(*arr);
		else if (size < 17 && len - (*count + 3) >= 0)
			*count += print_three_byte(*arr);
		else if (len - (*count + 4) >= 0)
			*count += print_four_byte(*arr);
		else
			break ;
		arr++;
	}
}

int		ft_put_w_str(unsigned int *arr, t_flags flags)
{
	int i;
	int len;
	int	space;
	int	z;

	i = 0;
	space = 0;
	z = -1;
	len = get_len_of_w_str(arr, flags.dot_width);
	(flags.min_width > 0) ? space = flags.min_width - len : space;
	while (space-- > 0)
		write(1, " ", 1);
	while (++z < flags.num_width - len)
		write(1, "0", 1);
	print_w_str(arr, &i, len);
	if (!arr)
	{
		i += 6;
		write(1, "(null)", 6);
	}
	(flags.min_width < 0) ? space = -(flags.min_width) - len : space;
	(flags.min_width < 0) ? flags.min_width = -(flags.min_width) : space;
	while (space-- > 0)
		write(1, " ", 1);
	return (i + ((flags.min_width - len > 0) ? flags.min_width - len : 0) + z);
}

int		ft_put_u_char(unsigned int c, t_flags flags)
{
	int	len;
	int	size;
	int	count;

	size = count_bits(c);
	count = 0;
	len = 0;
	if (flags.dot_width)
		len = flags.dot_width;
	if (size < 8)
	{
		count++;
		write(1, &c, 1);
	}
	else if (size < 12)
		count += print_two_byte(c);
	else if (size < 17)
		count += print_three_byte(c);
	else
		count += print_four_byte(c);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:17:35 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 16:47:55 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_str_help(t_flags flags, int *len, int *zero, char *str)
{
	int	space;

	space = 0;
	if (((flags.flag >> 11) & 1U) && flags.dot_width != -1
	&& flags.dot_width < *len)
		*len = flags.dot_width;
	if (ft_strlen(str) == 1 && *str == '0' && !flags.dot_width
	&& !((flags.flag >> 13) & 1U))
		*len = 0;
	(flags.min_width > 0) ? space = flags.min_width - *len : space;
	if ((flags.flag >> 10) & 1U)
		write(1, " ", 1);
	while (space-- > 0)
		write(1, " ", 1);
	while (((flags.flag >> 11) & 1U) && *zero < flags.num_width - *len)
	{
		write(1, "0", 1);
		*zero += 1;
	}
	if ((flags.flag >> 17) & 1U && ft_strlen(str) == 3 && !flags.dot_width)
		*len -= 1;
}

int		ft_put_str(char *str, t_flags flags)
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
	ft_put_str_help(flags, &len, &zero, str);
	if (str == NULL)
		write(1, "(null)", len);
	else if (!(ft_strlen(str) == 1 && *str == '0' &&
	!flags.dot_width && !((flags.flag >> 13) & 1U)))
		write(1, str, len);
	(flags.min_width < 0) ? space = -(flags.min_width) - len : space;
	(flags.min_width < 0) ? flags.min_width = -(flags.min_width) : space;
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
	(flags.min_width < 0) ? space = -(flags.min_width) - 1 : space;
	(flags.min_width < 0) ? flags.min_width = -(flags.min_width) : space;
	while (space-- > 0)
		write(1, " ", 1);
	return (1 + ((flags.min_width - 1 > 0) ? flags.min_width - 1 : 0) + zero);
}

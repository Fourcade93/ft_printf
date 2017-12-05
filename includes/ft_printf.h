/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:11:14 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/05 16:41:21 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			min_width;
	int			num_width;
	int			dot_width;
	short		flag;
}				t_flags;

/*
**outputs
*/
int		ft_itoa_base(int64_t val, int base, int up_low, t_flags flags);
int		ft_putstr(char *str, t_flags flags);
int		ft_put_w_str(int *arr, t_flags flags);
int		ft_put_char(int n, t_flags flags);
int		ft_uint_itoa_base(size_t n, size_t base, int up_low, t_flags flags);

/*
**helpers
*/
int		get_len(int64_t n, int base);
int		ft_strlen(char *str);
int		ft_arrlen(int *arr);
int		get_uint_len(size_t n, size_t base);

/*
**put calls
*/
int		ft_putpoint(long long n, t_flags flags);
int		ft_uphex_itoa(unsigned int n, t_flags flags);
int		ft_lowhex_itoa(unsigned int n, t_flags flags);
int		ft_dec_itoa(int n, t_flags flags);
int		ft_oct_itoa(unsigned int n, t_flags flags);
int		ft_uint_itoa(unsigned int n, t_flags flags);

/*
**put long calls
*/
int		ft_l_uphex_itoa(unsigned long int n, t_flags flags);
int		ft_l_lowhex_itoa(unsigned long int n, t_flags flags);
int		ft_l_dec_itoa(long int n, t_flags flags);
int		ft_l_oct_itoa(unsigned long int n, t_flags flags);
int		ft_l_uint_itoa(unsigned long int n, t_flags flags);

/*
**put long long calls
*/
int		ft_ll_uphex_itoa(unsigned long long int n, t_flags flags);
int		ft_ll_lowhex_itoa(unsigned long long int n, t_flags flags);
int		ft_ll_dec_itoa(long long int n, t_flags flags);
int		ft_ll_oct_itoa(unsigned long long int n, t_flags flags);
int		ft_ll_uint_itoa(unsigned long long int n, t_flags flags);

/*
**put char calls
*/
int		ft_char_uphex_itoa(unsigned int n, t_flags flags);
int		ft_char_lowhex_itoa(unsigned int n, t_flags flags);
int		ft_char_dec_itoa(int n, t_flags flags);
int		ft_char_oct_itoa(unsigned int n, t_flags flags);
int		ft_char_uint_itoa(unsigned int n, t_flags flags);

/*
**put short calls
*/
int		ft_short_uphex_itoa(unsigned int n, t_flags flags);
int		ft_short_lowhex_itoa(unsigned int n, t_flags flags);
int		ft_short_dec_itoa(int n, t_flags flags);
int		ft_short_oct_itoa(unsigned int n, t_flags flags);
int		ft_short_uint_itoa(unsigned int n, t_flags flags);

/*
**put max calls
*/
int		ft_max_uphex_itoa(uintmax_t n, t_flags flags);
int		ft_max_lowhex_itoa(uintmax_t n, t_flags flags);
int		ft_max_dec_itoa(intmax_t n, t_flags flags);
int		ft_max_oct_itoa(uintmax_t n, t_flags flags);
int		ft_max_uint_itoa(uintmax_t n, t_flags flags);

/*
**put size_t calls
*/
int		ft_z_uphex_itoa(size_t n, t_flags flags);
int		ft_z_lowhex_itoa(size_t n, t_flags flags);
int		ft_z_dec_itoa(size_t n, t_flags flags);
int		ft_z_oct_itoa(size_t n, t_flags flags);
int		ft_z_uint_itoa(size_t n, t_flags flags);

/*
**general
*/
int		ft_printf(const char *av, ...);

#endif

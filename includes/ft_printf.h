/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:11:14 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 16:43:35 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define L 1
# define LL 2
# define MAX 3
# define Z 4
# define H 5
# define HH 6
# define HASH 7
# define PLUS 8
# define MINUS 9
# define SPACE 10
# define STR 11
# define OX_X 12
# define O0 13
# define UI 14
# define DEC 15
# define UOCT 16
# define P 17

typedef struct	s_flags
{
	int			min_width;
	int			num_width;
	int			dot_width;
	int			flag;
}				t_flags;

/*
**outputs
*/
int				ft_itoa_base(int64_t val, int base, int up_low, t_flags flags);
int				ft_put_str(char *str, t_flags flags);
int				ft_put_w_str(unsigned int *arr, t_flags flags);
int				ft_put_char(int n, t_flags flags);
int				ft_uint_itoa_base(size_t n, size_t base, int up_low,
t_flags flags);
int				ft_put_w_str(unsigned int *arr, t_flags flags);
int				ft_put_u_char(unsigned int c, t_flags flags);

/*
**printf helpers
*/
int				ft_check_c(char c);
int				ft_get_num(const char *av, int *i, t_flags *flags);
int				back_i(const char *av, int *i, t_flags flags);
int				get_spec(const char *av, int *i, va_list args);

/*
**helpers
*/
int				get_len(int64_t n, int base, int *stop, t_flags flags);
int				ft_strlen(char *str);
int				ft_arrlen(int *arr);

/*
**put unicode helps
*/
int				get_uint_len(size_t n, size_t base);
int				count_bits(unsigned int n);
int				print_four_byte(unsigned int n);
int				print_three_byte(unsigned int n);
int				print_two_byte(unsigned int n);

/*
**put calls
*/
int				ft_putpoint(long long n, t_flags flags);
int				ft_uphex_itoa(unsigned int n, t_flags flags);
int				ft_lowhex_itoa(unsigned int n, t_flags flags);
int				ft_dec_itoa(int n, t_flags flags);
int				ft_oct_itoa(unsigned int n, t_flags flags);
int				ft_uint_itoa(unsigned int n, t_flags flags);

/*
**put long calls
*/
int				ft_l_uphex_itoa(unsigned long int n, t_flags flags);
int				ft_l_lowhex_itoa(unsigned long int n, t_flags flags);
int				ft_l_dec_itoa(long int n, t_flags flags);
int				ft_l_oct_itoa(unsigned long int n, t_flags flags);
int				ft_l_uint_itoa(unsigned long int n, t_flags flags);

/*
**put long long calls
*/
int				ft_ll_uphex_itoa(unsigned long long int n, t_flags flags);
int				ft_ll_lowhex_itoa(unsigned long long int n, t_flags flags);
int				ft_ll_dec_itoa(long long int n, t_flags flags);
int				ft_ll_oct_itoa(unsigned long long int n, t_flags flags);
int				ft_ll_uint_itoa(unsigned long long int n, t_flags flags);

/*
**put char calls
*/
int				ft_char_uphex_itoa(unsigned int n, t_flags flags);
int				ft_char_lowhex_itoa(unsigned int n, t_flags flags);
int				ft_char_dec_itoa(int n, t_flags flags);
int				ft_char_oct_itoa(unsigned int n, t_flags flags);
int				ft_char_uint_itoa(unsigned int n, t_flags flags);

/*
**put short calls
*/
int				ft_short_uphex_itoa(unsigned int n, t_flags flags);
int				ft_short_lowhex_itoa(unsigned int n, t_flags flags);
int				ft_short_dec_itoa(int n, t_flags flags);
int				ft_short_oct_itoa(unsigned int n, t_flags flags);
int				ft_short_uint_itoa(size_t n, t_flags flags);

/*
**put max calls
*/
int				ft_max_uphex_itoa(uintmax_t n, t_flags flags);
int				ft_max_lowhex_itoa(uintmax_t n, t_flags flags);
int				ft_max_dec_itoa(intmax_t n, t_flags flags);
int				ft_max_oct_itoa(uintmax_t n, t_flags flags);
int				ft_max_uint_itoa(uintmax_t n, t_flags flags);

/*
**put size_t calls
*/
int				ft_z_uphex_itoa(size_t n, t_flags flags);
int				ft_z_lowhex_itoa(size_t n, t_flags flags);
int				ft_z_oct_itoa(size_t n, t_flags flags);
int				ft_z_uint_itoa(size_t n, t_flags flags);

/*
**general
*/
int				ft_printf(const char *av, ...);

#endif

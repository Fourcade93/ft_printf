/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:13:22 by fmallaba          #+#    #+#             */
/*   Updated: 2017/12/12 17:47:59 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_STRUCT_H
# define FUNC_STRUCT_H

typedef int	(*t_func_put)();

typedef struct	s_func
{
	char		spec;
	t_func_put	(func);
}				t_func;

t_func	g_funcs[8][15] = {
	{
		{'s', ft_put_str},
		{'S', ft_put_w_str},
		{'p', ft_putpoint},
		{'d', ft_dec_itoa},
		{'D', ft_ll_dec_itoa},
		{'i', ft_dec_itoa},
		{'o', ft_oct_itoa},
		{'O', ft_ll_oct_itoa},
		{'u', ft_uint_itoa},
		{'U', ft_z_uint_itoa},
		{'x', ft_lowhex_itoa},
		{'X', ft_uphex_itoa},
		{'c', ft_put_char},
		{'C', ft_put_u_char},
		{0, 0}
	},
	{
		{'d', ft_l_dec_itoa},
		{'D', ft_l_dec_itoa},
		{'i', ft_l_dec_itoa},
		{'o', ft_l_oct_itoa},
		{'O', ft_l_oct_itoa},
		{'u', ft_l_uint_itoa},
		{'U', ft_l_uint_itoa},
		{'x', ft_l_lowhex_itoa},
		{'X', ft_l_uphex_itoa},
		{'p', ft_putpoint},
		{'c', ft_put_u_char},
		{'C', ft_put_u_char},
		{'s', ft_put_w_str},
		{'S', ft_put_w_str},
		{0, 0}
	},
	{
		{'d', ft_ll_dec_itoa},
		{'D', ft_ll_dec_itoa},
		{'i', ft_ll_dec_itoa},
		{'o', ft_ll_oct_itoa},
		{'O', ft_ll_oct_itoa},
		{'u', ft_ll_uint_itoa},
		{'U', ft_ll_uint_itoa},
		{'x', ft_ll_lowhex_itoa},
		{'X', ft_ll_uphex_itoa},
		{'p', ft_putpoint},
		{'c', ft_put_u_char},
		{'C', ft_put_u_char},
		{'s', ft_put_w_str},
		{0, 0}
	},
	{
		{'d', ft_max_dec_itoa},
		{'D', ft_max_dec_itoa},
		{'i', ft_max_dec_itoa},
		{'o', ft_max_oct_itoa},
		{'O', ft_max_oct_itoa},
		{'u', ft_max_uint_itoa},
		{'U', ft_max_uint_itoa},
		{'x', ft_max_lowhex_itoa},
		{'X', ft_max_uphex_itoa},
		{'p', ft_putpoint},
		{'c', ft_put_u_char},
		{'C', ft_put_u_char},
		{'s', ft_put_w_str},
		{'S', ft_put_w_str},
		{0, 0}
	},
	{
		{'d', ft_ll_dec_itoa},
		{'D', ft_ll_dec_itoa},
		{'i', ft_ll_dec_itoa},
		{'o', ft_z_oct_itoa},
		{'O', ft_z_oct_itoa},
		{'u', ft_z_uint_itoa},
		{'U', ft_z_uint_itoa},
		{'x', ft_z_lowhex_itoa},
		{'X', ft_z_uphex_itoa},
		{'p', ft_putpoint},
		{'c', ft_put_u_char},
		{'C', ft_put_u_char},
		{'s', ft_put_w_str},
		{'S', ft_put_w_str},
		{0, 0}
	},
	{
		{'d', ft_short_dec_itoa},
		{'D', ft_short_dec_itoa},
		{'i', ft_short_dec_itoa},
		{'o', ft_short_oct_itoa},
		{'O', ft_short_oct_itoa},
		{'u', ft_short_uint_itoa},
		{'U', ft_short_uint_itoa},
		{'x', ft_short_lowhex_itoa},
		{'X', ft_short_uphex_itoa},
		{'p', ft_putpoint},
		{'c', ft_put_char},
		{'C', ft_put_u_char},
		{'s', ft_put_str},
		{'S', ft_put_w_str},
		{0, 0}
	},
	{
		{'d', ft_char_dec_itoa},
		{'D', ft_char_dec_itoa},
		{'i', ft_char_dec_itoa},
		{'o', ft_char_oct_itoa},
		{'O', ft_char_oct_itoa},
		{'u', ft_char_uint_itoa},
		{'U', ft_char_uint_itoa},
		{'x', ft_char_lowhex_itoa},
		{'X', ft_char_uphex_itoa},
		{'p', ft_putpoint},
		{'c', ft_put_char},
		{'C', ft_put_u_char},
		{'s', ft_put_str},
		{'S', ft_put_w_str},
		{0, 0}
	}
};

#endif

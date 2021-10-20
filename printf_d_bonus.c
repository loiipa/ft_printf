/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:37:16 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:29:58 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void			write_d(t_option *opt, int *len, long long d)
{
	int				d_len;
	int				zero_num;

	d_len = check_len(d, 10);
	zero_num = check_width_len(opt, d, &d_len, 10);
	write_space(opt, len, d_len, -1);
	if (opt->flag_plus == 1 && d >= 0)
		*len += write(1, "+", 1);
	else if (opt->flag_plus == 2 && d >= 0)
		*len += write(1, " ", 1);
	else if (d < 0)
		*len += write(1, "-", 1);
	while (zero_num-- > 0)
		*len += write(1, "0", 1);
	if (d != 0 || opt->precision != 0)
		write_sign(d, 0, len, 10);
	write_space(opt, len, d_len, 1);
}

static void			specifier_d_origin(t_option *opt, va_list ap, int *len)
{
	int				d;

	d = va_arg(ap, int);
	write_d(opt, len, d);
}

void				specifier_d(t_option *opt, va_list ap, int *len)
{
	long			ld;
	long long		lld;
	short			hd;
	signed char		hhd;

	if (opt->length == 1)
		ld = va_arg(ap, long);
	else if (opt->length == 2)
		lld = va_arg(ap, long long);
	else if (opt->length == 3)
		hd = va_arg(ap, int);
	else if (opt->length == 4)
		hhd = va_arg(ap, int);
	if (opt->length == 1)
		write_d(opt, len, ld);
	else if (opt->length == 2)
		write_d(opt, len, lld);
	else if (opt->length == 3)
		write_d(opt, len, hd);
	else if (opt->length == 4)
		write_d(opt, len, hhd);
	else
		specifier_d_origin(opt, ap, len);
}

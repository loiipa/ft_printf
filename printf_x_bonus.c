/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 01:58:07 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:45 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	write_x(t_option *opt, int *len, char c, unsigned long long x)
{
	int				x_len;
	int				zero_num;

	opt->flag_plus = 0;
	x_len = check_un_len(x, 16);
	zero_num = check_un_width_len(opt, x, &x_len, 16);
	write_space(opt, len, x_len, -1);
	if (x > 0 && opt->flag == 1 && c == 'x')
		*len += write(1, "0x", 2);
	else if (x > 0 && opt->flag == 1 && c == 'X')
		*len += write(1, "0X", 2);
	while (zero_num-- > 0)
		*len += write(1, "0", 1);
	if (x != 0 || opt->precision != 0)
		write_unsign(x, 'x' - c, len, 16);
	write_space(opt, len, x_len, 1);
}

static void	specifier_x_origin(t_option *opt, va_list ap, int *len, char c)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	write_x(opt, len, c, x);
}

void		specifier_x(t_option *opt, va_list ap, int *len, char c)
{
	unsigned long		lx;
	unsigned long long	llx;
	unsigned short		hx;
	unsigned char		hhx;

	if (opt->length == 1)
		lx = va_arg(ap, unsigned long);
	else if (opt->length == 2)
		llx = va_arg(ap, unsigned long long);
	else if (opt->length == 3)
		hx = va_arg(ap, unsigned int);
	else if (opt->length == 4)
		hhx = va_arg(ap, unsigned int);
	if (opt->length == 1)
		write_x(opt, len, c, lx);
	else if (opt->length == 2)
		write_x(opt, len, c, llx);
	else if (opt->length == 3)
		write_x(opt, len, c, hx);
	else if (opt->length == 4)
		write_x(opt, len, c, hhx);
	else
		specifier_x_origin(opt, ap, len, c);
}

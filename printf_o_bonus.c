/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_o_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 01:58:07 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:15 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	write_o(t_option *opt, int *len, unsigned long long o)
{
	int				o_len;
	int				zero_num;

	opt->flag_plus = 0;
	o_len = check_un_len(o, 8);
	zero_num = check_un_width_len(opt, o, &o_len, 8);
	write_space(opt, len, o_len, -1);
	if (o > 0 && opt->flag == 1 && opt->precision <= check_un_len(o, 8))
		*len += write(1, "0", 1);
	while (zero_num-- > 0)
		*len += write(1, "0", 1);
	if (o != 0 || opt->precision != 0 || opt->flag != 0)
		write_unsign(o, 0, len, 8);
	write_space(opt, len, o_len, 1);
}

static void	specifier_o_origin(t_option *opt, va_list ap, int *len)
{
	unsigned int	o;

	o = va_arg(ap, unsigned int);
	write_o(opt, len, o);
}

void		specifier_o(t_option *opt, va_list ap, int *len)
{
	unsigned long		lo;
	unsigned long long	llo;
	unsigned short		ho;
	unsigned char		hho;

	if (opt->length == 1)
		lo = va_arg(ap, unsigned long);
	else if (opt->length == 2)
		llo = va_arg(ap, unsigned long long);
	else if (opt->length == 3)
		ho = va_arg(ap, unsigned int);
	else if (opt->length == 4)
		hho = va_arg(ap, unsigned int);
	if (opt->length == 1)
		write_o(opt, len, lo);
	else if (opt->length == 2)
		write_o(opt, len, llo);
	else if (opt->length == 3)
		write_o(opt, len, ho);
	else if (opt->length == 4)
		write_o(opt, len, hho);
	else
		specifier_o_origin(opt, ap, len);
}

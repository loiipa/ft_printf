/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 01:45:41 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:25 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		write_u(t_option *opt, int *len, unsigned long long u)
{
	int					u_len;
	int					zero_num;

	opt->flag_plus = 0;
	u_len = check_un_len(u, 10);
	zero_num = check_un_width_len(opt, u, &u_len, 10);
	write_space(opt, len, u_len, -1);
	while (zero_num-- > 0)
		*len += write(1, "0", 1);
	if (u != 0 || opt->precision != 0)
		write_unsign(u, 0, len, 10);
	write_space(opt, len, u_len, 1);
}

static void		specifier_u_origin(t_option *opt, va_list ap, int *len)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	write_u(opt, len, u);
}

void			specifier_u(t_option *opt, va_list ap, int *len)
{
	unsigned long		lu;
	unsigned long long	llu;
	unsigned short		hu;
	unsigned char		hhu;

	if (opt->length == 1)
		lu = va_arg(ap, unsigned long);
	else if (opt->length == 2)
		llu = va_arg(ap, unsigned long long);
	else if (opt->length == 3)
		hu = va_arg(ap, unsigned int);
	else if (opt->length == 4)
		hhu = va_arg(ap, unsigned int);
	if (opt->length == 1)
		write_u(opt, len, lu);
	else if (opt->length == 2)
		write_u(opt, len, llu);
	else if (opt->length == 3)
		write_u(opt, len, hu);
	else if (opt->length == 4)
		write_u(opt, len, hhu);
	else
		specifier_u_origin(opt, ap, len);
}

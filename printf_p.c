/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:59:40 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:30 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			specifier_p(t_option *opt, va_list ap, int *len)
{
	unsigned long long	p;
	int					p_len;
	int					zero_num;

	p = (unsigned long long)va_arg(ap, void *);
	opt->flag = 1;
	opt->flag_plus = 0;
	p_len = check_un_len(p, 16);
	zero_num = check_un_width_len(opt, p, &p_len, 16);
	if (p == 0)
		p_len += 2;
	write_space(opt, len, p_len, -1);
	*len += write(1, "0x", 2);
	while (zero_num-- > 0)
		*len += write(1, "0", 1);
	if (p != 0 || opt->precision != 0)
		write_unsign(p, 0, len, 16);
	write_space(opt, len, p_len, 1);
}

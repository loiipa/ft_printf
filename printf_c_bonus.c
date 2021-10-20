/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:23:22 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:29:54 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		ft_lc_len(int *c_len, int *c)
{
	int				i;

	i = 0;
	*c_len = 0;
	if (*c < 0x80)
		*c_len += 1;
	else if (*c < 0x800)
		*c_len += 2;
	else if (*c < 0x10000)
		*c_len += 3;
	else if (*c < 0x200000)
		*c_len += 4;
}

void			specifier_c(t_option *opt, va_list ap, int *len)
{
	int		c;
	int		c_len;

	c = va_arg(ap, int);
	if (opt->length == 1 && c > 127)
	{
		ft_lc_len(&c_len, &c);
		write_space(opt, len, c_len, -1);
		write_wchar(len, &c);
		write_space(opt, len, c_len, 1);
	}
	else
	{
		write_space(opt, len, 1, -1);
		*len += write(1, &c, 1);
		write_space(opt, len, 1, 1);
	}
}

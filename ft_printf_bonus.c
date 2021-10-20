/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:39:00 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:07 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void		set_opt(t_option *opt)
{
	opt->flag = 0;
	opt->flag_minus = 0;
	opt->flag_plus = 0;
	opt->width = 0;
	opt->precision = -1;
	opt->length = 0;
}

int				ft_printf(const char *str, ...)
{
	int			len;
	va_list		ap;
	t_option	opt;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			set_opt(&opt);
			str = meet_percent(&opt, (char *)str, ap, &len);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}

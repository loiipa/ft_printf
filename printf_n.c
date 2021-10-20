/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:17:12 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:27 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			specifier_n_origin(va_list ap, int *len)
{
	int		*n;

	n = va_arg(ap, int *);
	if (n)
		*n = *len;
}

void				specifier_n(t_option *opt, va_list ap, int *len)
{
	long			*ln;
	long long		*lln;
	short			*hn;
	signed char		*hhn;

	if (opt->length == 1)
		ln = va_arg(ap, long *);
	else if (opt->length == 2)
		lln = va_arg(ap, long long *);
	else if (opt->length == 3)
		hn = va_arg(ap, short *);
	else if (opt->length == 4)
		hhn = va_arg(ap, signed char *);
	if (opt->length == 1 && ln)
		*ln = *len;
	else if (opt->length == 2 && lln)
		*lln = *len;
	else if (opt->length == 3 && hn)
		*hn = *len;
	else if (opt->length == 4 && hhn)
		*hhn = *len;
	else
		specifier_n_origin(ap, len);
}

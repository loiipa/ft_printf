/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_g_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:29:05 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:40 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int				check_llarray_len(t_ll *ll)
{
	int				i;
	int				distance;

	distance = ll->count_i - DECIMAL_SIZE;
	i = distance * 18 + check_un_len(ll->num[ll->count_i], 10);
	if (ll->count_i == DECIMAL_SIZE && ll->num[DECIMAL_SIZE] == 0)
		i = 0;
	return (i);
}

static int		convert_g_to_fe(t_option *opt, t_ll *ll, int i, char *c)
{
	if (i == 0 && ll->count_d == DECIMAL_SIZE)
	{
		if (opt->flag == 1)
			opt->precision--;
		*c = 'f';
	}
	else if (i == 0 && ll->num[DECIMAL_SIZE - 1] < 100000000000000)
	{
		opt->precision--;
		*c = 'e';
	}
	else if (ll->num[DECIMAL_SIZE] >= 10 && i > opt->precision)
	{
		opt->precision--;
		*c = 'e';
	}
	else if (i > 0)
	{
		opt->precision -= i;
		*c = 'f';
	}
	else
		return (0);
	return (1);
}

void			set_g(t_option *opt, t_ll *ll, char *c)
{
	unsigned long long	dec;
	unsigned long long	digit;

	ll->count_g = 0;
	if (*c != 'g')
		return ;
	ll->count_g = 1;
	digit = 1000000000000000000;
	if (!(convert_g_to_fe(opt, ll, check_llarray_len(ll), c)))
	{
		if (opt->precision == 0)
			opt->precision++;
		dec = ll->num[DECIMAL_SIZE - 1];
		while (digit >= 10 && (dec % digit) / (digit / 10) == 0)
		{
			digit /= 10;
			opt->precision++;
		}
		*c = 'f';
	}
	if (opt->precision < 0)
		opt->precision = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_f_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:01 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:36 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_round(t_ll *ll, int j, unsigned long long digit)
{
	int			tmp;

	if (ll->num[j] % digit > 5 * digit / 10)
		ll->num[j] += digit;
	else if (ll->num[j] % digit == 5 * digit / 10)
	{
		tmp = j - 1;
		while (tmp >= 0 && ll->num[tmp] == 0)
			tmp--;
		if (tmp >= 0)
			ll->num[j] += digit;
		else if (tmp < 0 && ll->num[DECIMAL_SIZE] % 2 == 1)
			ll->num[j] += digit;
	}
	while (j < BUFFER_SIZE)
	{
		if (ll->num[j] >= 1000000000000000000)
		{
			ll->num[j + 1]++;
			ll->num[j] %= 1000000000000000000;
		}
		j++;
	}
}

void			round_num(t_option *opt, t_ll *ll, char c)
{
	int					i;
	int					j;
	unsigned long long	digit;

	i = -1;
	j = DECIMAL_SIZE;
	digit = 1;
	while (i < opt->precision)
	{
		i += 18;
		j--;
	}
	i -= opt->precision;
	if (j < 0)
	{
		j = 0;
		i = 0;
	}
	while (i-- >= 0)
		digit *= 10;
	check_round(ll, j, digit);
	if (c == 'e' && opt->flag_plus != 2 && ll->num[DECIMAL_SIZE] >= 10)
		set_e(ll, c);
}

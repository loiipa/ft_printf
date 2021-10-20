/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_g_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:29:05 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:43 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int		convert_e_to_f(t_option *opt, t_ll *ll, char *c)
{
	if (opt->precision == 0 && ll->count_e == -4 && ll->num[DECIMAL_SIZE] == 1)
	{
		*c = 'f';
		opt->precision = 4;
		ll->num[DECIMAL_SIZE] = 0;
		ll->num[DECIMAL_SIZE - 1] = 100000000000000;
		return (1);
	}
	return (0);
}

static int		convert_f_to_e(t_option *opt, t_ll *ll, char *c)
{
	int					i;

	i = check_llarray_len(ll);
	if (opt->precision == 0 && ll->num[DECIMAL_SIZE] >= 10 \
	&& i > ll->origin_precision)
	{
		*c = 'e';
		set_e(ll, *c);
		return (0);
	}
	else if (opt->precision == 0 || opt->flag == 1)
		return (0);
	return (1);
}

static void		recheck_precision(t_option *opt, t_ll *ll, int i, int j)
{
	unsigned long long	div;
	unsigned long long	digit;

	while (i <= DECIMAL_SIZE - 1 && opt->precision > 0)
	{
		digit = 10;
		while (j++ < 18)
			digit *= 10;
		while (digit <= 1000000000000000000 && opt->precision > 0 \
		&& i != DECIMAL_SIZE)
		{
			div = ll->num[i] % digit;
			if (div / (digit / 10) > 0)
				i = DECIMAL_SIZE;
			else
			{
				opt->precision--;
				digit *= 10;
			}
		}
		i++;
		j = 18;
	}
}

void			reset_g(t_option *opt, t_ll *ll, char *c)
{
	int					i;
	int					j;

	if (!ll->count_g)
		return ;
	if (convert_e_to_f(opt, ll, c))
		;
	else if ((!(convert_f_to_e(opt, ll, c))))
		return ;
	i = (DECIMAL_SIZE - 1) - ((opt->precision - 1) / 18);
	j = (opt->precision - 1) % 18 + 1;
	if (i < 0)
		i = 0;
	recheck_precision(opt, ll, i, j);
	convert_e_to_f(opt, ll, c);
}

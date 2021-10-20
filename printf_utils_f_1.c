/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_f_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:11:49 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:35 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			write_f_space(t_option *opt, int *len, int x_len, int sign)
{
	int					i;

	i = -1;
	if (sign == 2 && opt->flag_minus == 2 && opt->width > 0)
		while (++i < opt->width - x_len - opt->precision)
			*len += write(1, "0", 1);
	else if (opt->flag_minus == sign && opt->width > 0)
		while (++i < opt->width - x_len - opt->precision)
			*len += write(1, " ", 1);
}

void			check_f_len(t_option *opt, t_ll *ll, int *length, char c)
{
	int			distance;

	distance = ll->count_i - DECIMAL_SIZE;
	*length = distance * 18 + check_un_len(ll->num[ll->count_i], 10);
	if (ll->sign)
		(*length)++;
	if (!ll->sign && opt->flag_plus > 0)
		(*length)++;
	if (opt->precision > 0)
		(*length)++;
	else if (opt->flag == 1)
		(*length)++;
	if (c == 'e')
	{
		if (check_len(ll->count_e, 10) < 3)
			*length += 4;
		else
			*length += check_len(ll->count_e, 10) + 2;
	}
}

static t_ull	check_digit(t_ll *ll, int i, int count)
{
	unsigned long long	digit;

	digit = 1;
	if (i == count)
		while (ll->num[i] / 10 >= digit)
			digit *= 10;
	else
		digit = 100000000000000000;
	return (digit);
}

void			write_integer(t_ll ll, int *len)
{
	unsigned long long	div;
	unsigned long long	digit;
	char				c;
	int					i;

	i = ll.count_i;
	while (i >= DECIMAL_SIZE)
	{
		digit = check_digit(&ll, i, ll.count_i);
		while (digit > 0)
		{
			div = ll.num[i] / digit;
			c = '0' + div;
			*len += write(1, &c, 1);
			ll.num[i] %= digit;
			digit /= 10;
		}
		i--;
	}
}

void			write_decimal(int p, t_ll ll, int *len)
{
	unsigned long long	div;
	unsigned long long	digit;
	char				c;
	int					i;

	if (p == 0)
		return ;
	i = DECIMAL_SIZE - 1;
	while (i >= ll.count_d)
	{
		digit = 100000000000000000;
		while (digit > 0)
		{
			div = ll.num[i] / digit;
			c = '0' + div;
			*len += write(1, &c, 1);
			if (--p == 0)
				return ;
			ll.num[i] %= digit;
			digit /= 10;
		}
		i--;
	}
	while (p-- > 0)
		*len += write(1, "0", 1);
}

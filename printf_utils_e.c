/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:01 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:34 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			make_count(t_ll *ll)
{
	ll->count_i = BUFFER_SIZE - 1;
	while (!ll->num[ll->count_i] && ll->count_i > DECIMAL_SIZE)
		ll->count_i--;
	ll->count_d = 1;
	while (!ll->num[ll->count_d] && ll->count_d < DECIMAL_SIZE)
		ll->count_d++;
}

static void		set_e_2(t_ll *ll)
{
	int				i;

	while (ll->num[DECIMAL_SIZE] >= 10)
	{
		i = 0;
		while (++i < BUFFER_SIZE)
		{
			ll->num[i - 1] += ll->num[i] % 10 * 100000000000000000;
			ll->num[i] /= 10;
		}
		ll->count_e++;
	}
}

void			set_e(t_ll *ll, char c)
{
	int				i;
	int				j;

	if (c == 'f' || ll->fraction == 0)
		return ;
	if ((i = ll->count_i - DECIMAL_SIZE) > 0)
	{
		j = ll->count_d - 1;
		while (++j < BUFFER_SIZE)
			ll->num[j - i] = ll->num[j];
		ll->count_e += i * 18;
	}
	else
		while (ll->num[DECIMAL_SIZE] == 0)
		{
			j = ll->count_i;
			while (--j > 0)
				ll->num[j + 1] = ll->num[j];
			ll->count_e -= 18;
		}
	set_e_2(ll);
	make_count(ll);
}

void			write_e_end(t_ll ll, int *len, int c)
{
	int			digit;
	int			div;

	if (c != 'e')
		return ;
	if (ll.count_e >= 0)
		*len += write(1, "e+", 2);
	else
		*len += write(1, "e-", 2);
	if (ll.count_e < 0)
		ll.count_e *= -1;
	digit = 1;
	while (ll.count_e / 10 >= digit)
		digit *= 10;
	if (ll.count_e < 10)
		*len += write(1, "0", 1);
	while (digit > 0)
	{
		div = ll.count_e / digit;
		c = '0' + div;
		*len += write(1, &c, 1);
		ll.count_e %= digit;
		digit /= 10;
	}
}

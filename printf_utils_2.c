/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:03:16 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:33 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			write_unsign(
				unsigned long long num, int flag, int *len, unsigned int base)
{
	unsigned long long	div;
	unsigned long long	digit;
	char				c;

	digit = 1;
	while (num / base >= digit)
		digit *= base;
	while (digit > 0)
	{
		div = num / digit;
		if (div < 10)
			c = '0' + div;
		else if (!flag)
			c = 'a' + div - 10;
		else
			c = 'A' + div - 10;
		*len += write(1, &c, 1);
		num %= digit;
		digit /= base;
	}
}

void			write_sign(long long num, int flag, int *len, unsigned int base)
{
	long long		div;
	long long		digit;
	char			c;

	digit = 1;
	while (num / base >= digit || num / base * -1 >= digit)
		digit *= base;
	while (digit > 0)
	{
		div = num / digit;
		if (div < 0)
			div *= -1;
		if (div < 10)
			c = '0' + div;
		else if (!flag)
			c = 'a' + div - 10;
		else
			c = 'A' + div - 10;
		*len += write(1, &c, 1);
		num %= digit;
		digit /= base;
	}
}

void			write_space(t_option *opt, int *len, int x_len, int sign)
{
	int					i;

	i = -1;
	if (sign == -1 && opt->flag_minus != 1 && opt->width > 0)
		while (++i < opt->width - x_len)
			*len += write(1, " ", 1);
	else if (sign == 2 && opt->flag_minus == sign && opt->width > 0)
		while (++i < opt->width - x_len)
			*len += write(1, "0", 1);
	else if (opt->flag_minus == sign && opt->width > 0)
		while (++i < opt->width - x_len)
			*len += write(1, " ", 1);
}

void			write_wchar(int *len, int *c)
{
	unsigned char	c2[2];
	unsigned char	c3[3];
	unsigned char	c4[4];

	if (*c < 0x800)
	{
		c2[0] = 0b11000000 | (*c >> 6);
		c2[1] = 0b10000000 | (*c & 0b111111);
		*len += write(1, c2, 2);
	}
	else if (*c < 0x10000)
	{
		c3[0] = 0b11100000 | (*c >> 12);
		c3[1] = 0b10000000 | (*c >> 6 & 0b111111);
		c3[2] = 0b10000000 | (*c & 0b111111);
		*len += write(1, c3, 3);
	}
	else if (*c < 0x200000)
	{
		c4[0] = 0b11110000 | (*c >> 18);
		c4[1] = 0b10000000 | (*c >> 12 & 0b111111);
		c4[2] = 0b10000000 | (*c >> 6 & 0b111111);
		c4[3] = 0b10000000 | (*c & 0b111111);
		*len += write(1, c4, 4);
	}
}

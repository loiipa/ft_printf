/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:55:54 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:11:32 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_un_len(unsigned long long n, unsigned int base)
{
	unsigned int		len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int		check_len(long long n, unsigned int base)
{
	int					len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int		check_un_width_len(
		t_option *opt, unsigned long long n, int *length, unsigned int base)
{
	int					zero_num;

	zero_num = 0;
	if (opt->precision > *length && opt->precision >= 0)
	{
		zero_num = opt->precision - *length;
		*length = opt->precision;
	}
	if (n == 0 && opt->precision == 0 && base != 8)
		*length = 0;
	else if (n == 0 && opt->precision == 0 && base == 8 && opt->flag == 0)
		*length = 0;
	else if (n > 0 && base == 8 && opt->flag == 1 && \
	opt->precision <= check_un_len(n, 8))
		(*length)++;
	else if (n > 0 && base == 16 && opt->flag == 1)
		*length += 2;
	if (opt->flag_minus == 2 && opt->width > 0 && opt->precision == -1)
	{
		zero_num = opt->width - *length;
		*length = opt->width;
	}
	return (zero_num);
}

int		check_width_len(
		t_option *opt, long long n, int *length, unsigned int base)
{
	int					zero_num;

	zero_num = 0;
	if (opt->precision > *length && opt->precision >= 0)
	{
		zero_num = opt->precision - *length;
		*length = opt->precision;
	}
	if (n < 0)
		(*length)++;
	if (n == 0 && opt->precision == 0)
		*length = 0;
	if (n >= 0 && opt->flag_plus > 0)
		(*length)++;
	if (base == 16 && opt->flag == 1)
		*length += 2;
	if (opt->flag_minus == 2 && opt->width > 0 && opt->precision == -1)
	{
		zero_num = opt->width - *length;
		*length = opt->width;
	}
	return (zero_num);
}

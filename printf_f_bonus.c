/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:00:40 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:10 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void			write_f_flag(t_option *opt, t_ll *ll, int *len)
{
	if (opt->flag_plus == 1 && !ll->sign)
		*len += write(1, "+", 1);
	else if (opt->flag_plus == 2 && !ll->sign)
		*len += write(1, " ", 1);
	else if (ll->sign)
		*len += write(1, "-", 1);
}

static void			make_num(t_ll *ll, int exp, int i)
{
	if (exp > 0)
		while (exp-- > 0)
		{
			i = DECIMAL_SIZE - 1;
			while (++i < BUFFER_SIZE)
				ll->num[i] *= 2;
			i = DECIMAL_SIZE - 1;
			while (++i < BUFFER_SIZE)
				if (ll->num[i] >= 1000000000000000000)
				{
					ll->num[i + 1]++;
					ll->num[i] %= 1000000000000000000;
				}
		}
	else if (exp < 0)
		while (exp++ < 0)
		{
			i = DECIMAL_SIZE + 1;
			while (--i > 0)
				if (ll->num[i] % 2 == 1)
					ll->num[i - 1] += 1000000000000000000;
			i = DECIMAL_SIZE + 1;
			while (--i > 0)
				ll->num[i] /= 2;
		}
}

static int			make_tll(t_ll *ll, double f)
{
	void			*v;
	unsigned char	*s;
	int				i;

	v = &f;
	s = (unsigned char *)v;
	i = -1;
	ll->sign = s[7] >> 7;
	ll->exponent = (s[7] & 0b1111111) * 16 + (s[6] >> 4) - 1023;
	s[7] = 0;
	s[6] = (s[6] & 0b1111);
	ll->fraction = *(long long *)v;
	if (ll->exponent == -1023 && ll->fraction == 0)
		ll->fraction = 0;
	else if (ll->exponent == 1024)
		return (0);
	if (!(ll->exponent == -1023 && ll->fraction == 0))
		ll->fraction |= 4503599627370496;
	while (++i < BUFFER_SIZE)
		ll->num[i] = 0;
	ll->num[DECIMAL_SIZE] = ll->fraction;
	make_num(ll, ll->exponent - 52, 0);
	make_count(ll);
	ll->count_e = 0;
	return (1);
}

static void			specifier_s_inf(t_option *opt, t_ll *ll, int *len)
{
	char	*s;
	int		s_len;
	int		flag_len;

	if (ll->sign == 1)
		s = "-inf";
	else if (ll->fraction == 0)
		s = "inf";
	else
		s = "nan";
	s_len = ft_strlen(s);
	flag_len = 0;
	if (opt->flag_plus > 0 && ll->fraction == 0 && ll->sign == 0)
		flag_len++;
	write_space(opt, len, s_len + flag_len, -1);
	if (opt->flag_plus == 1 && ll->fraction == 0 && ll->sign == 0)
		*len += write(1, "+", 1);
	else if (opt->flag_plus == 2 && ll->fraction == 0 && ll->sign == 0)
		*len += write(1, " ", 1);
	*len += write(1, s, s_len);
	write_space(opt, len, s_len, 1);
}

void				specifier_fge(t_option *opt, va_list ap, int *len, char c)
{
	double		f;
	int			f_len;
	t_ll		ll;

	f = va_arg(ap, double);
	if (opt->precision == -1)
		opt->precision = 6;
	ll.origin_precision = opt->precision;
	if (!make_tll(&ll, f))
		return (specifier_s_inf(opt, &ll, len));
	set_g(opt, &ll, &c);
	set_e(&ll, c);
	round_num(opt, &ll, c);
	reset_g(opt, &ll, &c);
	check_f_len(opt, &ll, &f_len, c);
	write_f_space(opt, len, f_len, 0);
	write_f_flag(opt, &ll, len);
	write_f_space(opt, len, f_len, 2);
	write_integer(ll, len);
	if (opt->precision != 0 || opt->flag == 1)
		*len += write(1, ".", 1);
	write_decimal(opt->precision, ll, len);
	write_e_end(ll, len, c);
	write_f_space(opt, len, f_len, 1);
}

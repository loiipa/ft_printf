/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_branch_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:25:23 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:29:37 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char		*check_specifier(t_option *opt, char *str, va_list ap, int *len)
{
	if (*str == 'c')
		specifier_c(opt, ap, len);
	else if (*str == 's')
		specifier_s(opt, ap, len);
	else if (*str == 'p')
		specifier_p(opt, ap, len);
	else if (*str == 'd' || *str == 'i')
		specifier_d(opt, ap, len);
	else if (*str == 'u')
		specifier_u(opt, ap, len);
	else if (*str == 'x' || *str == 'X')
		specifier_x(opt, ap, len, *str);
	else if (*str == '%')
		specifier_olo(opt, len);
	else if (*str == 'n')
		specifier_n(opt, ap, len);
	else if (*str == 'f' || *str == 'e' || *str == 'g')
		specifier_fge(opt, ap, len, *str);
	else if (*str == 'o')
		specifier_o(opt, ap, len);
	else
		str--;
	return (str);
}

static char		*check_length(t_option *opt, char *str, va_list ap, int *len)
{
	if (*str == 'l' || *str == 'h')
	{
		if (*str == 'l' && *(str + 1) == 'l')
			opt->length = 2;
		else if (*str == 'h' && *(str + 1) == 'h')
			opt->length = 4;
		else if (*str == 'l')
			opt->length = 1;
		else if (*str == 'h')
			opt->length = 3;
		str++;
		if (opt->length % 2 == 0)
			str++;
	}
	str = check_specifier(opt, str, ap, len);
	return (str);
}

static char		*check_precision(t_option *opt, char *str, va_list ap, int *len)
{
	if (*str == '.' && *(str + 1) == '*')
	{
		opt->precision = va_arg(ap, int);
		str += 2;
		if (opt->precision < 0)
			opt->precision = -1;
	}
	else if (*str == '.')
	{
		opt->precision++;
		while (*(++str) >= '0' && *str <= '9')
			opt->precision = opt->precision * 10 + *str - '0';
	}
	str = check_length(opt, str, ap, len);
	return (str);
}

static char		*check_width(t_option *opt, char *str, va_list ap, int *len)
{
	if (*str == '*')
	{
		opt->width = va_arg(ap, int);
		str++;
		if (opt->width < 0)
		{
			opt->flag_minus = 1;
			opt->width *= -1;
		}
	}
	else if (*str >= '1' && *str <= '9')
		while (*str >= '0' && *str <= '9')
		{
			opt->width = opt->width * 10 + *str - '0';
			str++;
		}
	str = check_precision(opt, str, ap, len);
	return (str);
}

char			*meet_percent(t_option *opt, char *str, va_list ap, int *len)
{
	while (*(++str) == '#' || *str == '-' || *str == '0' \
	|| *str == '+' || *str == ' ')
	{
		if (*str == '#')
			opt->flag = 1;
		else if (*str == '-')
			opt->flag_minus = 1;
		else if (*str == '0' && opt->flag_minus != 1)
			opt->flag_minus = 2;
		else if (*str == '+')
			opt->flag_plus = 1;
		else if (*str == ' ' && opt->flag_plus != 1)
			opt->flag_plus = 2;
	}
	str = check_width(opt, str, ap, len);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:53:20 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 16:08:18 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int		ft_ls_len(int *s_len, int *s)
{
	int				i;

	i = 0;
	*s_len = 0;
	while (s[i])
	{
		if (s[i] < 0x80)
			*s_len += 1;
		else if (s[i] < 0x800)
			*s_len += 2;
		else if (s[i] < 0x10000)
			*s_len += 3;
		else if (s[i] < 0x200000)
			*s_len += 4;
		i++;
	}
	return (i);
}

static void		specifier_ls(t_option *opt, va_list ap, int *len)
{
	int		i;
	int		count;
	int		*s;
	int		s_len;

	s = va_arg(ap, int *);
	i = -1;
	if (!s)
		s = L"(null)";
	count = ft_ls_len(&s_len, s);
	if (s_len > opt->precision && opt->precision >= 0)
		s_len = opt->precision;
	write_space(opt, len, s_len, 0);
	write_space(opt, len, s_len, 2);
	while (++i < count)
	{
		if (s[i] < 128)
			*len += write(1, &s[i], 1);
		else
			write_wchar(len, &s[i]);
	}
	write_space(opt, len, 1, 1);
}

void			specifier_s(t_option *opt, va_list ap, int *len)
{
	char	*s;
	int		s_len;

	if (opt->length == 1)
		specifier_ls(opt, ap, len);
	else
	{
		s = va_arg(ap, char *);
		if (!s)
			s = "(null)";
		s_len = ft_strlen(s);
		if (s_len > opt->precision && opt->precision >= 0)
			s_len = opt->precision;
		write_space(opt, len, s_len, 0);
		write_space(opt, len, s_len, 2);
		*len += write(1, s, s_len);
		write_space(opt, len, s_len, 1);
	}
}

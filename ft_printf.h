/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:01:48 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 13:25:24 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFFER_SIZE	196
# define DECIMAL_SIZE	128

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef unsigned long long	t_ull;

typedef struct	s_option
{
	int			flag;
	int			flag_minus;
	int			flag_plus;
	int			width;
	int			precision;
	int			length;
}				t_option;

typedef struct	s_ll
{
	int			sign;
	int			exponent;
	long long	fraction;
	int			count_i;
	int			count_d;
	int			count_e;
	int			count_g;
	int			origin_precision;
	t_ull		num[BUFFER_SIZE];
}				t_ll;

int				ft_printf(const char *str, ...);
char			*meet_percent(t_option *opt, char *str, va_list ap, int *len);
void			specifier_c(t_option *opt, va_list ap, int *len);
void			specifier_s(t_option *opt, va_list ap, int *len);
void			specifier_p(t_option *opt, va_list ap, int *len);
void			specifier_d(t_option *opt, va_list ap, int *len);
void			specifier_u(t_option *opt, va_list ap, int *len);
void			specifier_x(t_option *opt, va_list ap, int *len, char c);
void			specifier_olo(t_option *opt, int *len);
void			specifier_n(t_option *opt, va_list ap, int *len);
void			specifier_fge(t_option *opt, va_list ap, int *len, char c);
void			specifier_o(t_option *opt, va_list ap, int *len);
int				check_un_len(unsigned long long n, unsigned int base);
int				check_len(long long n, unsigned int base);
void			write_unsign
				(unsigned long long num, int flag, int *len, unsigned int base);
void			write_sign
				(long long num, int flag, int *len, unsigned int base);
int				check_un_width_len
				(t_option *opt, unsigned long long n, int *length,
				unsigned int base);
int				check_width_len
				(t_option *opt, long long n, int *length, unsigned int base);
void			write_space(t_option *opt, int *len, int x_len, int sign);
void			write_wchar(int *len, int *c);
void			write_f_space(t_option *opt, int *len, int x_len, int sign);
void			check_f_len(t_option *opt, t_ll *ll, int *length, char c);
void			write_integer(t_ll ll, int *len);
void			write_decimal(int p, t_ll ll, int *len);
void			make_count(t_ll *ll);
void			set_e(t_ll *ll, char c);
void			write_e_end(t_ll ll, int *len, int c);
void			round_num(t_option *opt, t_ll *ll, char c);
void			set_g(t_option *opt, t_ll *ll, char *c);
int				check_llarray_len(t_ll *ll);
void			reset_g(t_option *opt, t_ll *ll, char *c);

#endif

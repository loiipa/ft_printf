/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_olo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:22:51 by cjang             #+#    #+#             */
/*   Updated: 2021/03/15 15:30:17 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void				specifier_olo(t_option *opt, int *len)
{
	write_space(opt, len, 1, 2);
	write_space(opt, len, 1, 0);
	*len += write(1, "%", 1);
	write_space(opt, len, 1, 1);
}

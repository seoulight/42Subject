/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:25:15 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 13:37:38 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_memaddress(va_list ap, t_flags *flags)
{
	int					cnt;
	char				*add;
	unsigned long long	mem;

	cnt = 2;
	mem = va_arg(ap, unsigned long long);
	add = ft_uitoa_base(mem, "0123456789abcdef");
	cnt += ft_strlen(add);
	if (!flags -> minus && !flags -> zero)
		cnt += print_padding(flags -> width - cnt, FALSE);
	ft_putstr_fd("0x", 1);
	if (flags -> zero)
		cnt += print_padding(flags -> width - cnt, TRUE);
	ft_putstr_fd(add, 1);
	if (flags -> minus)
		cnt += print_padding(flags -> width - cnt, FALSE);
	free(add);
	return (cnt);
}
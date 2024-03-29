/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:21:49 by gkim              #+#    #+#             */
/*   Updated: 2021/02/11 18:29:53 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg(va_list ap, t_flags *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (flags->type == 'u')
		return (ft_ulltoa_base(va_arg(ap, unsigned int), "0123456789"));
	else if (flags->type == 'x')
	{
		return (ft_ulltoa_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (flags->type == 'X')
		return (ft_ulltoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}

static int	print_positive(char *num, t_flags *flags)
{
	int len;
	int cnt;

	cnt = ft_strlen(num);
	len = cnt < flags->prec ? flags->prec : cnt;
	if (!flags->minus)
		cnt += print_padding(flags->width - len, flags->zero);
	cnt += print_padding(flags->prec - ft_strlen(num), TRUE);
	ft_putstr_fd(num, 1);
	if (flags->minus)
		cnt += print_padding(flags->width - len, FALSE);
	return (cnt);
}

static int	print_negative(char *num, t_flags *flags)
{
	int	len;
	int	cnt;

	cnt = ft_strlen(num);
	len = flags->prec + 1 > cnt ? flags->prec + 1 : cnt;
	if (!flags->minus && !flags->zero)
		cnt += print_padding(flags->width - len, FALSE);
	ft_putchar_fd(*num, 1);
	num++;
	if (!flags->minus && flags->zero)
		cnt += print_padding(flags->width - len, TRUE);
	cnt += print_padding(flags->prec - ft_strlen(num), TRUE);
	ft_putstr_fd(num, 1);
	if (flags->minus)
		cnt += print_padding(flags->width - cnt, FALSE);
	return (cnt);
}

int			print_num(va_list ap, t_flags *flags)
{
	char	*num;
	int		cnt;

	cnt = 0;
	if (!(num = get_arg(ap, flags)))
		return (-1);
	if (flags->prec == 0 && *num == '0')
	{
		free(num);
		num = ft_strdup("");
	}
	if (*num == '-')
		cnt += print_negative(num, flags);
	else
		cnt += print_positive(num, flags);
	free(num);
	return (cnt);
}

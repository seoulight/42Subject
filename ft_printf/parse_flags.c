/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:16:13 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 22:44:06 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flags **flags)
{
	(*flags)->zero = FALSE;
	(*flags)->minus = FALSE;
	(*flags)->width = -1;
	(*flags)->prec = -1;
}

static void	set_prec(const char **format, va_list ap, t_flags *flg)
{
	(*format)++;
	flg->prec = 0;
	if (**format == '*')
	{
		flg->prec = va_arg(ap, int);
		if (flg->prec < 0)
			flg->prec = -1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		flg->prec = (flg->prec * 10) + (**format - '0');
		(*format)++;
	}
	(*format)--;
}

static void	set_width(const char **format, va_list ap, t_flags *flg)
{
	flg->width = 0;
	if (**format == '*')
	{
		flg->width = va_arg(ap, int);
		if (flg->width < 0)
		{
			flg->minus = TRUE;
			flg->width *= -1;
		}
	}
	else
	{
		while (ft_isdigit(**format))
		{
			flg->width = (flg->width * 10) + (**format - '0');
			(*format)++;
		}
		(*format)--;
	}
}

void		parse_flags(const char **format, va_list ap, t_flags **flg)
{
	init_flags(flg);
	while (!ft_isalpha(**format) && **format)
	{
		if (**format == '%')
		{
			(*flg)->type = '%';
			return ;
		}
		else if (**format == '-')
			(*flg)->minus = TRUE;
		else if (**format == '0')
			(*flg)->zero = TRUE;
		else if (**format == '.')
			set_prec(format, ap, *flg);
		else if (ft_isdigit(**format) || **format == '*')
			set_width(format, ap, *flg);
		(*format)++;
	}
	(*flg)->type = **format;
	if ((*flg)->zero && ((*flg)->minus || (*flg)->prec > -1))
		(*flg)->zero = FALSE;
}

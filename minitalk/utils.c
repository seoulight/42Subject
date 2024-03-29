/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:23:23 by gkim              #+#    #+#             */
/*   Updated: 2021/10/03 16:07:05 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	jump_space(const char *str, int *idx)
{
	while (str[*idx] == '\n' || str[*idx] == '\t' || str[*idx] == '\v'
		|| str[*idx] == '\r' || str[*idx] == '\f' || str[*idx] == ' ')
		(*idx)++;
}

static void	chk_mark(const char c, int *mark, int *idx)
{
	if (c == '-')
	{
		*mark = -1;
		(*idx)++;
	}
	else if (c == '+')
		(*idx)++;
}

int	ft_atoi(const char *nptr)
{
	int	mark;
	int	num;
	int	i;

	i = 0;
	mark = 1;
	num = 0;
	jump_space(nptr, &i);
	chk_mark(nptr[i], &mark, &i);
	while (nptr[i] >= '0' && nptr[i] < '9')
	{
		num = num * 10 + (nptr[i] - '0') * mark;
		i++;
	}
	return (num);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

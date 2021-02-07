/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <40_90@naver.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 05:20:17 by gkim              #+#    #+#             */
/*   Updated: 2020/11/23 19:13:12 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_numeric(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!is_numeric(*str))
			return (0);
		str++;
	}
	return (1);
}

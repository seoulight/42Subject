/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <40_90@naver.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:48:59 by gkim              #+#    #+#             */
/*   Updated: 2020/11/23 19:23:53 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = lowcase(str[i]);
		i++;
	}
	return (str);
}
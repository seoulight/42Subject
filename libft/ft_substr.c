/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:08:13 by gkim              #+#    #+#             */
/*   Updated: 2020/12/22 13:59:34 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (result);
	i = 0;
	while (i < (int)len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

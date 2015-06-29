/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:39:58 by mzane             #+#    #+#             */
/*   Updated: 2015/01/30 07:41:09 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (s1[i] && i < n)
	{
		if (!s2[i] || s2[i] != s1[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - s2[i]);
	return (0);
}

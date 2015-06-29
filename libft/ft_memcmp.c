/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:16:59 by mzane             #+#    #+#             */
/*   Updated: 2015/05/19 23:50:29 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*ss1;
	unsigned const char		*ss2;

	ss1 = s1;
	ss2 = s2;
	while (n)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		n--;
		ss1++;
		ss2++;
	}
	return (0);
}

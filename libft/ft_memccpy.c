/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:14:29 by mzane             #+#    #+#             */
/*   Updated: 2014/11/10 18:10:06 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)s2)[i] != (char)c)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		i++;
	}
	if (i == n && ((char *)s1)[i] != (char)c)
		return (NULL);
	else
		return (&((char *)s1)[i + 1]);
}

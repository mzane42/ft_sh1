/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 10:11:23 by mzane             #+#    #+#             */
/*   Updated: 2014/11/14 10:13:06 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		max_size;
	size_t		i;
	size_t		dest_size;
	size_t		j;

	dest_size = ft_strlen(dest);
	j = dest_size + ft_strlen(src);
	i = 0;
	max_size = size - dest_size - 1;
	while (size > dest_size + 1 && src[i])
	{
		dest[dest_size++] = src[i++];
		max_size--;
	}
	dest[dest_size] = '\0';
	if (size < j - ft_strlen(src))
		return (size + ft_strlen(src));
	else
		return (j);
}

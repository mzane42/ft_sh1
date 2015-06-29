/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:11:52 by mzane             #+#    #+#             */
/*   Updated: 2014/11/08 16:59:30 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cpy;

	cpy = (char*)malloc(sizeof(char*) * n);
	cpy = ft_strncpy(cpy, src, n);
	dest = (void*)ft_strncpy(dest, cpy, n);
	free(cpy);
	return (dest);
}

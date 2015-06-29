/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:17:35 by mzane             #+#    #+#             */
/*   Updated: 2014/11/10 18:14:42 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 1;
	while (s[i])
		i++;
	while (1)
	{
		if (s[i] == c)
		{
			p = &((char *)s)[i];
			return (p);
		}
		if (!i)
			break ;
		i--;
	}
	return (0);
}

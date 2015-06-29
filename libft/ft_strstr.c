/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:27:26 by mzane             #+#    #+#             */
/*   Updated: 2015/05/19 23:53:25 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char *s1, const char *s2)
{
	unsigned int i;
	unsigned int s2len;

	i = -1;
	if (ft_strlen(s2) == 0)
		return (s1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	s2len = ft_strlen(s2);
	while (s1[++i + s2len - 1])
		if (ft_memcmp(s1 + i, s2, s2len) == 0)
			return (s1 + i);
	return (NULL);
}

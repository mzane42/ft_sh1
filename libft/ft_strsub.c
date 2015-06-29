/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:37:04 by mzane             #+#    #+#             */
/*   Updated: 2015/01/12 16:23:46 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	end;

	i = 0;
	end = start + len;
	if (!s)
		return (NULL);
	else if ((str = (char *)malloc(len + 1)) && end != 0)
	{
		while (start < end)
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}

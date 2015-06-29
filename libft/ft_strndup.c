/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 17:05:21 by mzane             #+#    #+#             */
/*   Updated: 2015/05/12 17:06:11 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*ndup;

	i = 0;
	if (!(ndup = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i <= n)
	{
		ndup[i] = str[i];
		i++;
	}
	ndup[i] = '\0';
	return (ndup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 10:00:55 by mzane             #+#    #+#             */
/*   Updated: 2014/11/14 10:02:26 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;
	int	i;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}

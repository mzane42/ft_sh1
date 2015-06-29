/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:49:05 by mzane             #+#    #+#             */
/*   Updated: 2014/11/12 14:44:13 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	len;
	int	counter;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		counter = 0;
		while (counter < len)
		{
			(*f)(s);
			s++;
			counter++;
		}
	}
}

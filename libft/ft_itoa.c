/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:33:56 by mzane             #+#    #+#             */
/*   Updated: 2015/02/04 01:17:54 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		div;

	i = 0;
	div = 1;
	str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1);
	if (n == -2147483648)
		return ("-2147483648");
	else if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		str[i++] = (n / div) + 48;
		n %= div;
		div /= 10;
	}
	str[i] = '\0';
	return (str);
}

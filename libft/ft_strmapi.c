/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:49:05 by mzane             #+#    #+#             */
/*   Updated: 2015/02/04 01:40:24 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	counter;
	char			*new_str;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	len = ft_strlen (s);
	new_str = ft_strnew (len);
	counter = 0;
	while (counter < len)
	{
		new_str[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	return (new_str);
}

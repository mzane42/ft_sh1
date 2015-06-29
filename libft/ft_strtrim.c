/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:50:16 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/20 03:04:44 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	str = (char *)malloc(sizeof(char) * (unsigned int)(end - start + 1));
	if (!str)
		return (NULL);
	while ((start <= end) && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

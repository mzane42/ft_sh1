/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 10:05:57 by mzane             #+#    #+#             */
/*   Updated: 2015/05/01 18:24:45 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}

static char		*ft_addword(char const *s, int *i, char c)
{
	int		size;
	char	*word;
	int		j;

	size = *i;
	j = 0;
	while (s[size] && s[size] != c)
		size++;
	size = size - *i;
	word = (char *)malloc(sizeof(char) * size + 1);
	while (s[*i] != c && s[*i])
		word[j++] = s[(*i)++];
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		words;

	i = 0;
	j = 0;
	words = ft_countword(s, c);
	str = (char **)malloc(sizeof(char *) * words + 1);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		str[j++] = ft_addword(s, &i, c);
	}
	str[j] = NULL;
	return (str);
}

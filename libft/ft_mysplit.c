/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:47:13 by mzane             #+#    #+#             */
/*   Updated: 2015/05/21 04:18:28 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *buf)
{
	int		i;
	int		words;

	if (!buf)
		return (-1);
	words = 0;
	i = -1;
	while (buf[++i])
	{
		while (buf[i] && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n'))
			++i;
		if (buf[i])
		{
			while (buf[i] && buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
				++i;
			++words;
		}
		if (!buf[i])
			--i;
	}
	return (words);
}

static int	count_letters(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
		++i;
	return (i);
}

char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		pos;
	int		words;
	char	**tab;

	words = count_words(str);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);
	tab[words] = NULL;
	i = -1;
	pos = 0;
	while (++i < words)
	{
		while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
			++pos;
		tab[i] = (char *)malloc(sizeof(char) * count_letters((str + pos) + 1));
		j = 0;
		while (str[pos] && str[pos] != ' ' && str[pos] != '\t')
			tab[i][j++] = str[pos++];
		tab[i][j] = 0;
	}
	return (tab);
}

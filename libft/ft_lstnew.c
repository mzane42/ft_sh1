/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 12:38:34 by mzane             #+#    #+#             */
/*   Updated: 2015/02/04 01:38:42 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ma_list;
	void		*cpy;

	ma_list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!ma_list)
		return (NULL);
	if (content == NULL)
	{
		ma_list->content = NULL;
		ma_list->content_size = 0;
	}
	else
	{
		cpy = ft_memalloc(content_size);
		if (!cpy)
			return (NULL);
		ma_list->content = ft_memcpy(cpy, content, content_size);
		ma_list->content_size = content_size;
	}
	ma_list->next = NULL;
	return (ma_list);
}

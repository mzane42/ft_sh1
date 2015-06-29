/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubs1 <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:57:54 by aaubs1            #+#    #+#             */
/*   Updated: 2015/05/19 05:50:03 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void		*new;
	size_t		i;

	i = 0;
	if (ptr == NULL)
		return (NULL);
	if (size == 0)
		new = (void *)ft_memalloc(sizeof(char));
	else
		new = (void *)ft_memalloc(size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, (size) ? size : sizeof(char));
	if (old > size)
		ft_memcpy(new, ptr, (size) ? size : sizeof(char));
	else
		ft_memcpy(new, ptr, old);
	ft_memdel((void *)&ptr);
	return (new);
}

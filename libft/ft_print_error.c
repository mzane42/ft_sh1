/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 20:45:11 by mzane             #+#    #+#             */
/*   Updated: 2015/05/12 17:50:26 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(char *message, char *av)
{
	ft_putstr("error :  ");
	ft_putstr(av);
	ft_putstr(" ");
	ft_putendl(message);
}

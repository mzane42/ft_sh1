/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:55:12 by mzane             #+#    #+#             */
/*   Updated: 2015/05/22 15:12:55 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_env_size(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

int		ft_var_exists(char **env, char *var)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnequ(env[i], var, ft_strlen(var)))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_check_setenv(char *s, int i, int tmp)
{
	if (ft_strequ(s, "setenv"))
	{
		i = 1;
		tmp = 0;
	}
	else
	{
		i = 0;
		tmp = 1;
	}
}

int		av_size(char **av)
{
	int		i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}

void	del_av(char **av)
{
	int		i;

	i = 0;
	if (av)
	{
		while (av[i])
		{
			ft_strdel(&av[i]);
			i++;
		}
		free(av);
		av = NULL;
	}
}

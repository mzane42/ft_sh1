/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 01:18:43 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 13:46:39 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			ft_rm_var(t_params *p, char *var)
{
	int		env_size;
	int		pos_var;

	env_size = ft_env_size(p->env);
	pos_var = ft_var_exists(p->env, var);
	if (pos_var != -1)
	{
		pos_var++;
		while (pos_var < env_size)
		{
			p->env[pos_var - 1] = p->env[pos_var];
			pos_var++;
		}
		p->env[pos_var - 1] = NULL;
		del_var(p, var);
	}
	return (1);
}

void		check_error(t_params *p, char *var, int exists)
{
	if (exists != -1)
	{
		ft_rm_var(p, var);
		unsetenv_error(var, exists);
	}
	else
		unsetenv_error(var, -1);
}

int			ft_rm_env(char *buf, t_params *p)
{
	char		*var;
	char		**av;
	int			exists;
	int			i;

	av = ft_split(buf);
	i = 0;
	if (ft_strcmp(av[i], "unsetenv") == 0)
	{
		i = 1;
		while (av[i])
		{
			var = av[i];
			exists = ft_var_exists(p->env, var);
			check_error(p, var, exists);
			i++;
		}
	}
	else
		ft_putendl("usage : [unsetenv] [Var]");
	del_av(av);
	return (1);
}

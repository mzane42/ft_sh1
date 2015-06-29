/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 01:15:08 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 14:54:52 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			add_var(t_params *p, char **var, int pmt, char **tmp_env)
{
	int		pos_var;
	char	*name;
	char	*value;
	char	*tmp;

	name = var[0];
	value = var[1];
	if (value == NULL)
		value = " ";
	tmp = ft_strjoin(name, "=");
	tmp = ft_strjoin(tmp, value);
	pos_var = ft_var_exists(tmp_env, name);
	if (pos_var != -1)
	{
		if (pmt == 1)
			p->env[pos_var] = tmp;
		else
			tmp_env[pos_var] = tmp;
	}
	else
		(pmt == 1) ? (ft_re_var(p, pos_var, tmp)) :
			(ft_tmp_var(tmp_env, pos_var, tmp));
	return (1);
}

void		ft_setenv(char *var, t_params *p, int tmp)
{
	char	**var_value;
	int		exists;
	char	**tmp_env;

	tmp_env = ft_dup_environ(p->env);
	var_value = ft_strsplit(var, '=');
	if (tmp == 1)
		exists = ft_var_exists(p->env, var_value[0]);
	else
		exists = ft_var_exists(tmp_env, var_value[0]);
	add_var(p, var_value, tmp, tmp_env);
	if (tmp == 1)
		set_env(p, var_value[0], var_value[1]);
	if (exists == -1)
		setenv_error(var_value[0], -1);
	else
		setenv_error(var_value[0], exists);
}

void		check_add(t_params *p, char *var, int tmp, int j)
{
	if (ft_strchr(var, '='))
		ft_setenv(var, p, tmp);
	if (!ft_strchr(var, '=') && j == 0)
	{
		j++;
		ft_putendl("usage setenv [setenv] [VAR=VALUE]");
	}
}

int			ft_add_env(char *buf, t_params *p)
{
	char	**av;
	int		i;
	int		j;
	int		tmp;

	j = 0;
	av = ft_split(buf);
	if (ft_strequ(av[0], "setenv"))
	{
		i = 1;
		tmp = 1;
	}
	else
	{
		i = 0;
		tmp = 0;
	}
	while (av[i])
	{
		check_add(p, av[i], tmp, j);
		i++;
	}
	del_av(av);
	return (1);
}

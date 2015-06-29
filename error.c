/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 18:42:14 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 13:01:41 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_tmp_var(char **tmp_env, int pos_var, char *tmp)
{
	pos_var = ft_env_size(tmp_env);
	tmp_env = ft_realloc((void*)tmp_env, sizeof(char *) * pos_var,
			sizeof(char *) * (pos_var + 2));
	tmp_env[pos_var] = tmp;
	tmp_env[pos_var + 1] = NULL;
}

void		ft_re_var(t_params *p, int pos_var, char *tmp)
{
	pos_var = ft_env_size(p->env);
	p->env = ft_realloc((void*)p->env, sizeof(char *) * pos_var,
			sizeof(char *) * (pos_var + 2));
	p->env[pos_var] = tmp;
	p->env[pos_var + 1] = NULL;
}

void		unsetenv_error(char *var, int exists)
{
	if (exists != -1)
	{
		ft_putstr("destruction de la variable ");
		ft_putstr(var);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("the variable ");
		ft_putstr(var);
		ft_putstr(" ");
		ft_putstr("doesn't exists");
		ft_putstr("\n");
	}
}

void		setenv_error(char *var, int exists)
{
	if (exists == -1)
	{
		ft_putstr("Creation de la variable ");
		ft_putstr(var);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("mise a jour de la variable ");
		ft_putstr(var);
		ft_putstr("\n");
	}
}

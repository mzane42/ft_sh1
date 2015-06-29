/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:50:39 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 12:52:58 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		**ft_dup_environ(char **environ)
{
	char		**copie;
	size_t		i;

	i = 0;
	while (environ && environ[i])
		i++;
	copie = (char **)malloc((i + 1) * sizeof(char *));
	if (copie == NULL)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		copie[i] = ft_strdup(environ[i]);
		i++;
	}
	copie[i] = NULL;
	return (copie);
}

t_params	*ft_get_params(int argc, char **argv, char **env)
{
	t_params	*p;
	int			i;

	i = 0;
	p = (t_params *)ft_memalloc(sizeof(t_params));
	p->argc = argc;
	p->argv = argv;
	p->path_2d = NULL;
	p->home = "";
	p->pwd = "";
	p->oldpwd = "";
	p->env = ft_dup_environ(env);
	ft_parse_env(p);
	return (p);
}

char		**copy_path(char *env)
{
	char	**elts;
	char	**path_2d;

	path_2d = NULL;
	elts = ft_strsplit(env, '=');
	path_2d = ft_strsplit(elts[1], ':');
	return (path_2d);
}

void		ft_parse_env(t_params *p)
{
	int		i;
	char	**elts;

	i = 0;
	while (p->env[i] != NULL)
	{
		if (ft_strncmp(p->env[i], "PATH=", 5) == 0)
			p->path_2d = copy_path(p->env[i]);
		else if (ft_strncmp(p->env[i], "HOME=", 5) == 0)
		{
			elts = ft_strsplit(p->env[i], '=');
			p->home = elts[1];
		}
		else if (ft_strncmp(p->env[i], "PWD=", 4) == 0)
		{
			elts = ft_strsplit(p->env[i], '=');
			p->pwd = elts[1];
		}
		else if (ft_strncmp(p->env[i], "OLDPWD=", 7 == 0))
		{
			elts = ft_strsplit(p->env[i], '=');
			p->oldpwd = elts[1];
		}
		i++;
	}
}

void		ft_print_env(t_params *p)
{
	int			i;

	i = 0;
	while (p->env[i] != NULL)
	{
		ft_putendl(p->env[i]);
		i++;
	}
}

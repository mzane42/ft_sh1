/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 20:26:50 by mzane             #+#    #+#             */
/*   Updated: 2015/05/21 03:58:37 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		improper_path(int ret, char *path)
{
	if (ret == -1)
		ft_print_error("cd: no such file or directory: ", path);
	else if (ret == -2)
		ft_print_error("cd: permission denied: ", path);
}

static char		*get_newdir(t_params *p, char *buf)
{
	char	*new_dir;
	char	*tmp;

	if (!ft_strncmp(buf, "./", 2))
		new_dir = ft_strjoin(p->pwd, ft_strchr(buf, '/'));
	else if (buf[0] == '/')
		new_dir = ft_strdup(buf);
	else if (!ft_strcmp(buf, "-"))
		new_dir = ft_strdup(p->oldpwd);
	else if (!ft_strcmp(buf, ".."))
		new_dir = ft_strlen(p->pwd) - ft_strlen(ft_strrchr(p->pwd, '/')) ?
			ft_strndup(p->pwd, ft_strlen(p->pwd)
					- ft_strlen(ft_strrchr(p->pwd, '/')) - 1)
			: ft_strdup("/");
	else
	{
		tmp = p->pwd[ft_strlen(p->pwd) - 1] != '/' ?
			ft_strjoin(p->pwd, "/") : NULL;
		new_dir = tmp != NULL ? ft_strjoin(tmp, buf) : ft_strjoin(p->pwd, buf);
		ft_strdel(&tmp);
	}
	return (new_dir);
}

static int		update_var(t_params *p, char *var, char *value)
{
	int		i;

	i = 0;
	while (p->env && p->env[i]
			&& ft_strncmp(p->env[i], var, ft_strlen(var)))
		i++;
	if (p->env[i])
	{
		p->env[i] = ft_strjoin(var, value);
		return (1);
	}
	return (0);
}

static void		update_env(t_params *p, char *new_dir)
{
	char	*tmp;

	p->oldpwd = p->pwd;
	if (ft_strstr(new_dir, "/nfs/"))
		p->pwd = ft_strdup(ft_strstr(new_dir, "/nfs/"));
	else
		p->pwd = ft_strdup(new_dir);
	if (!(update_var(p, "PWD=", p->pwd)))
	{
		tmp = ft_strjoin("setenv PWD ", p->pwd);
		ft_add_env(tmp, p);
		ft_strdel(&tmp);
	}
	if (!(update_var(p, "OLDPWD=", p->oldpwd)))
	{
		tmp = ft_strjoin("setenv OLDPWD ", p->oldpwd);
		ft_add_env(tmp, p);
		ft_strdel(&tmp);
	}
}

void			ft_cd(char *buf, t_params *p)
{
	char	**av;
	char	*new_dir;
	int		ret;
	int		size;

	ret = 0;
	av = ft_split(buf);
	new_dir = NULL;
	size = av_size(av);
	if (size > 2)
		ft_putendl("cd: syntax error");
	else if (size == 1 || (size == 2 && !ft_strcmp(av[1], "~")))
		new_dir = ft_strdup(p->home);
	else
		new_dir = get_newdir(p, av[1]);
	if (new_dir && !(ret = check_path(new_dir)) && !chdir(new_dir))
		update_env(p, new_dir);
	else if (new_dir && !(ret = check_path(new_dir)) && chdir(new_dir) == -1)
		ft_print_error("cd: not a directory: ", av[1]);
	if (new_dir && ret && av[1])
		improper_path(ret, av[1]);
	ft_strdel(&new_dir);
	del_av(av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 05:33:28 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 12:49:39 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			check_path(char *path)
{
	if (access(path, F_OK) == -1)
		return (-1);
	if (access(path, X_OK) == -1)
		return (-2);
	return (0);
}

void		set_env(t_params *p, char *var, char *value)
{
	if (ft_strncmp(var, "PATH", 4) == 0)
		p->path_2d = ft_strsplit(value, ':');
	else if (ft_strncmp(var, "HOME", 4) == 0)
		p->home = value;
	else if (ft_strncmp(var, "PWD", 3) == 0)
		p->pwd = value;
	else if (ft_strncmp(var, "OLDPWD", 6 == 0))
		p->oldpwd = value;
}

void		del_var(t_params *p, char *var)
{
	if (ft_strncmp(var, "PATH", 4) == 0)
		p->path_2d = NULL;
	else if (ft_strncmp(var, "HOME", 4) == 0)
		p->home = NULL;
	else if (ft_strncmp(var, "PWD", 3) == 0)
		p->pwd = NULL;
	else if (ft_strncmp(var, "OLDPWD", 6 == 0))
		p->oldpwd = NULL;
}

char		*build_path(char *path, char *command)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp1, command);
	ft_strdel(&tmp1);
	return (tmp2);
}

char		*ft_get_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = (char *)malloc((1024) * sizeof(char));
	if (pwd != NULL)
	{
		ft_bzero(pwd, 0);
		pwd = getcwd(pwd, 1024);
	}
	return (pwd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 19:18:27 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 12:52:39 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		improper_command(int ret, char *command)
{
	if (ret == -1 && (!ft_strncmp(command, "./", 2)
				|| !ft_strncmp(command, "../", 3) || command[0] == '/'))
		ft_print_error("ft_sh1: no such file or directory: ", command);
	else if (ret == -1)
		ft_print_error("ft_sh1: command not found: ", command);
	else if (ret == -2)
		ft_print_error("ft_sh1: permission denied: ", command);
}

static char		*check_command(char *command, t_params *p)
{
	char	*tmp;
	int		i;
	int		ret;

	ret = 0;
	tmp = NULL;
	if ((!ft_strncmp(command, "./", 2) || !ft_strncmp(command, "../", 3)
				|| command[0] == '/') && !(ret = check_path(command)))
		return (ft_strdup(command));
	if (p->path_2d == NULL)
		ft_putendl("ft_sh1: path is empty");
	else if (!ret)
	{
		i = -1;
		while (p->path_2d[++i])
		{
			ft_strdel(&tmp);
			tmp = build_path(p->path_2d[i], command);
			if (!(ret = check_path(tmp)))
				return (tmp);
		}
	}
	improper_command(ret, command);
	ft_strdel(&tmp);
	return (NULL);
}

int				fork_error(char **av)
{
	del_av(av);
	ft_putendl("command_proc: no child process created");
	return (-1);
}

int				command_proc(char *command, t_params *p)
{
	char	**av;
	char	*tmp;
	int		status;

	status = 0;
	init_pid();
	av = ft_split(command);
	if (av && (tmp = check_command(av[0], p)))
	{
		ft_strdel(&av[0]);
		av[0] = tmp;
		if ((g_pid.father = fork()) == -1)
			fork_error(av);
		if (g_pid.father)
			wait(&g_pid.id);
		else if (!g_pid.father)
		{
			execve(av[0], av, p->env);
			ft_print_error("ft_sh1: command not found: ", av[0]);
			exit(0);
		}
	}
	del_av(av);
	return (1);
}

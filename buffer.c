/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:49:45 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 13:25:09 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_display_prompt(void)
{
	char *s;

	s = NULL;
	s = ft_get_pwd();
	ft_putstr("\033[31m( : ");
	ft_putstr(s);
	ft_putstr(" > \033[0m");
}

int		ft_sh_begin_loop(t_params *p)
{
	char	*buf;
	char	*trim;
	int		i;

	i = 0;
	ft_display_prompt();
	catch_signal();
	while (get_next_line(0, &buf))
	{
		trim = ft_strtrim(buf);
		if (trim && *trim)
		{
			if (!ft_strequ(trim, ""))
				ft_read_action(trim, p);
			init_pid();
		}
		free(buf);
		free(trim);
		ft_display_prompt();
	}
	return (0);
}

int		ft_read_action(char *action, t_params *p)
{
	if (ft_builtins(action, p))
		return (1);
	else if (command_proc(action, p))
		return (1);
	else
		return (0);
}

void	ft_env(char *buf, t_params *p)
{
	char	**av;
	int		i;
	char	**env_tmp;
	int		j;

	j = 0;
	av = ft_split(buf);
	if (av_size(av) == 1)
		ft_print_env(p);
	else
	{
		i = 1;
		if (ft_strcmp(av[i], "-i") == 0)
		{
			env_tmp = (char **)malloc(sizeof(char *) * 1);
			env_tmp[0] = NULL;
			i++;
		}
		else
			env_tmp = ft_dup_environ(p->env);
		while (av[i] && ft_strchr(av[i], '='))
			ft_add_env(av[i++], p);
		command_proc(av[i], p);
	}
	del_av(av);
}

int		ft_builtins(char *buf, t_params *p)
{
	int		ret;

	ret = 1;
	if (buf != NULL)
	{
		if (ft_strequ(buf, "exit"))
			exit(1);
		else if (ft_strnequ(buf, "cd", 2))
			ft_cd(buf, p);
		else if (ft_strnequ(buf, "env", 3))
			ft_env(buf, p);
		else if (ft_strnequ(buf, "setenv", 6))
			ft_add_env(buf, p);
		else if (ft_strnequ(buf, "unsetenv ", 9))
			ft_rm_env(buf, p);
		else
			return (0);
	}
	return (ret);
}

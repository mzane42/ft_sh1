/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:44:50 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 14:29:22 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct		s_params
{
	char			**argv;
	int				argc;
	char			**env;
	char			**path_2d;
	char			*home;
	char			*pwd;
	char			*oldpwd;
}					t_params;

typedef struct		s_id
{
	int				id;
	pid_t			child;
	pid_t			father;
}					t_id;

t_id				g_pid;
void				catch_signal(void);
void				ft_check_setenv(char *s, int i, int tmp);
void				init_pid(void);
void				ignore_all_signals(void);
t_params			*ft_get_params(int argc, char **argv, char **env);
int					ft_sh_begin_loop(t_params *p);
int					ft_env_size(char **env);
void				ft_print_env(t_params *p);
void				ft_parse_env(t_params *p);
int					ft_exec_bin(char **new_path, char **args, t_params *p);
int					ft_sh_begin_loop(t_params *p);
int					ft_read_action(char *buf, t_params *p);
int					ft_builtins(char *action, t_params *p);
int					ft_add_env(char *buf, t_params *p);
int					add_var(t_params *p, char **var, int pmt, char **tmp_env);
int					ft_var_exists(char **env, char *var);
int					ft_rm_var(t_params *p, char *var);
int					ft_rm_env(char *buf, t_params *p);
void				unsetenv_error(char *var, int exists);
void				setenv_error(char *var, int exists);
int					ft_exists(char *path);
void				ft_cd(char *buf, t_params *p);
int					av_size(char **av);
void				del_av(char **av);
char				*build_path(char *path, char *command);
int					check_path(char *path);
int					command_proc(char *command, t_params *p);
char				*ft_get_pwd(void);
void				ft_display_prompt(void);
char				**ft_dup_environ(char **environ);
void				del_var(t_params *p, char *var);
void				set_env(t_params *p, char *var, char *value);
void				ft_tmp_var(char **tmp_env, int pos_var, char *tmp);
void				ft_re_var(t_params *p, int pos_var, char *tmp);

#endif

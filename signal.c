/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 05:15:47 by mzane             #+#    #+#             */
/*   Updated: 2015/05/23 12:52:49 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_sh.h"

static void		ignore_signal(int sig)
{
	(void)sig;
}

void			ignore_all_signals(void)
{
	int		i;

	i = -1;
	while (++i <= 64)
	{
		if (i != SIGKILL && i != SIGSTOP)
			signal(i, &ignore_signal);
	}
}

static void		handle_signal(int sig)
{
	if (g_pid.father || g_pid.child)
	{
		ft_putstr("\b\b");
		if (g_pid.father)
			kill(sig, g_pid.father);
		if (g_pid.child)
			kill(sig, g_pid.child);
	}
	else
	{
		if (sig == SIGINT)
		{
			ft_putstr("\b\b  ");
			ft_putchar('\n');
			ft_display_prompt();
		}
		else
			signal(sig, SIG_DFL);
	}
}

void			init_pid(void)
{
	g_pid.id = 0;
	g_pid.father = 0;
	g_pid.child = 0;
}

void			catch_signal(void)
{
	int		i;

	i = 0;
	while (i < 33)
	{
		signal(i, handle_signal);
		i++;
	}
}

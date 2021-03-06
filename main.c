/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:41:08 by mzane             #+#    #+#             */
/*   Updated: 2015/05/19 07:48:50 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_start_program(void)
{
	ft_putstr("\033[32m||=========================");
	ft_putendl("==============================||");
	ft_putendl("||$$$$===============================================$$$$||");
	ft_putendl("|||100|==========| RESERVE BANK OF AMERICA|=========|100|||");
	ft_putendl("||$$$$________ $ '------------------------'___________$$$||");
	ft_putendl("||<<|________|$|____________<< ____ >>________________$$$||");
	ft_putendl("||>>|________|$|_____________ |||..> ________XXXX_____$$$||");
	ft_putendl("||<<|________|$|__________||_<||__>|__||______________$$$||");
	ft_putendl("||>>|________|$|__________||__$$ --/__||__ XXXXXXXXX__$$$||");
	ft_putendl("||<<|____Free to Use______***__|__/__***______________$$$||");
	ft_putendl("||>>|____________________||_________||________________$$$||");
	ft_putendl("||<<$_____Rating: E_______| B.FRANKLIN |___XX_XXXXX___$$$||");
	ft_putendl("||||||=======================|==USA===|==============||||||");
	ft_putendl("|||100|================ONE=HUNDRED=DOLLARS==========|100|||");
	ft_putendl("||||||================================================|||||");
	ft_putstr("||========================");
	ft_putendl("===============================||\033[0m");
}

int		main(int argc, char **argv, char **env)
{
	t_params	*p;
	int			i;

	i = 0;
	ft_start_program();
	init_pid();
	p = ft_get_params(argc, argv, env);
	ignore_all_signals();
	ft_sh_begin_loop(p);
	return (0);
}

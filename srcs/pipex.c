/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:32 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/04 15:33:58 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_global	g;
	
	if (argc >= 5)
	{
		ft_init_struct(argc, argv, env, &g);
		//ft_parse_cmds(&g);
		//ft_init_pipe(&g);
		ft_free_tab(g.paths);
		ft_lstclear_pipex(&g.lst);
		ft_free_tab(g.cmd1);
		ft_free_tab(g.cmd2);
	}
	else
		ft_putstr_fd("Invalid number of arguments\n", 2);
	return (0);
}
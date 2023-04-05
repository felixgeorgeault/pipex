/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:32 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/05 18:26:50 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_global	g;
	
	if (argc >= 5)
	{
		ft_init_struct(argc, argv, env, &g);
		ft_parse_cmds(&g);
		ft_init_fork(&g, argv, env);
		ft_free_tab(g.paths);
		ft_lstclear_pipex(&g.lst);
	}
	else
		ft_putstr_fd("Invalid number of arguments\n", 2);
	return (0);
}

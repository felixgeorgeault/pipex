/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:32 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/11 18:32:39 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_global	g;

	if (argc)
	{
		ft_init_struct(argc, argv, env, &g);
		ft_parse_cmds(&g);
		ft_exec(env, &g);
		ft_waitpid(&g);
		ft_free_pipefds(&g);
		ft_free_pids(&g);
		ft_free_tab(g.paths);
		ft_lstclear_pipex(&g.lst);
	}
	return (0);
}

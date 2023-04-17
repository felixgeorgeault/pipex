/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:27:39 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/14 17:47:50 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_struct_vars(int argc, char **argv, t_global *g)
{
	g->paths = NULL;
	g->lst = NULL;
	g->pids = NULL;
	g->pipefd = NULL;
	g->argc = argc;
	g->nbr_cmds = g->argc - 3;
	g->nbr_pipe = g->nbr_cmds - 1;
	g->nbr_fork = g->nbr_cmds;
	g->outfile = open(argv[g->argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (g->outfile == -1)
		ft_error(g, "Failed to open outfile\n");
	g->infile = open(argv[1], O_RDONLY);
	if (g->infile == -1)
		ft_error(g, argv[1]);
}

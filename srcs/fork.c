/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/31 00:56:35 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(int pos, t_global *g)
{
	g->pids[pos] = fork();
	if (g->pids[pos] == -1)
		ft_error(g, FORK_ERR);
}

pid_t	*ft_createfork_array(t_global *g)
{
	pid_t	*array;

	array = malloc(sizeof(pid_t) * (g->nbr_fork));
	if (!array)
		ft_error(g, "Failed to create the fork array\n");
	return (array);
}

void	ft_first_child(t_global *g)
{
	ft_dup2(g->infile, STDIN_FILENO, g);
	ft_close(&g->infile, g);
	ft_dup2(g->pipefd[0][1], STDOUT_FILENO, g);
	ft_close(&g->pipefd[0][1], g);
}

void	ft_last_child(int pos, t_global *g)
{
	ft_dup2(g->pipefd[pos - 1][0], STDIN_FILENO, g);
	ft_close(&g->pipefd[pos - 1][0], g);
	ft_dup2(g->outfile, STDOUT_FILENO, g);
	ft_close(&g->outfile, g);
}

void	ft_middle_child(int pos, t_global *g)
{
	ft_dup2(g->pipefd[pos - 1][0], STDIN_FILENO, g);
	ft_close(&g->pipefd[pos - 1][0], g);
	ft_dup2(g->pipefd[pos][1], STDOUT_FILENO, g);
	ft_close(&g->pipefd[pos][1], g);
}

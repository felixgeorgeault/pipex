/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/12 15:12:05 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(int pos, t_global *g)
{
	g->pids[pos] = fork();
	if (g->pids[pos] == -1)
		ft_error(g, "An error occured on the fork function\n");
}

void	ft_createfork_tab(t_global *g)
{
	int		i;
	pid_t	*tab;

	i = 0;
	tab = NULL;
	tab = malloc(sizeof(pid_t) * (g->nbr_fork));
	if (!tab)
		ft_error(g, "Failed to create the fork array\n");
	g->pids = tab;
}

void	ft_first_child(int pos, char **env, t_global *g)
{
	ft_close_first_child(pos, g);
	ft_dup2(g->infile, STDIN_FILENO, g);
	ft_close(g->infile, g);
	ft_dup2(g->pipefd[pos][1], STDOUT_FILENO, g);
	ft_close(g->pipefd[pos][1], g);
	execve(g->lst->content[0], g->lst->content, env);
}

void	ft_last_child(int pos, char **env, t_global *g)
{
	ft_close_last_child((pos - 1), g);
	ft_dup2(g->pipefd[pos - 1][0], STDIN_FILENO, g);
	ft_close(g->pipefd[pos - 1][0], g);
	ft_dup2(g->outfile, STDOUT_FILENO, g);
	ft_close(g->outfile, g);
	execve(g->lst->content[0], g->lst->content, env);
}

void	ft_middle_child(int pos, char **env, t_global *g)
{
	ft_dup2(g->pipefd[pos - 1][0], STDIN_FILENO, g);
	ft_close(g->pipefd[pos - 1][0], g);
	ft_dup2(g->pipefd[pos][1], STDOUT_FILENO, g);
	ft_close(g->pipefd[pos][1], g);
	execve(g->lst->content[0], g->lst->content, env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:44:26 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/07 17:27:37 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int pos, char **env, t_global *g)
{
	if (pos == 0)
	{
		ft_dup2(g->file1, 0, g);
		ft_dup2(g->pipefd[pos][0], 1, g);
		execve(g->lst->content[0], g->lst->content, env);
		return ;
	}
	ft_dup2(g->pipefd[pos - 1][1], 0, g);
	ft_dup2(g->pipefd[pos][0], 1, g);
	execve(g->lst->content[0], g->lst->content, env);
}

static void	ft_parent(int pos, t_global *g)
{
	if (pos == g->nbr_fork)
	{
		ft_dup2(0, g->pipefd[pos][1], g);
		ft_dup2(g->file2, 1, g);
		return ;
	}
	ft_dup2(0, g->pipefd[pos - 1][1], g);
	ft_dup2(g->pipefd[pos][0], 1, g);
}

void	ft_exec(char **argv, char **env, t_global *g)
{
	int		i;
	t_pipex *head;
	int		status;
	
	i = 0;
	head = g->lst;
	g->nbr_pipe = g->nbr_cmds - 1;
	g->nbr_fork = g->nbr_pipe + 1;
	ft_createpipe_tab(g);
	ft_createfork_tab(g);
	g->file1 = open(argv[1], O_RDONLY);
	g->file2 = open(argv[g->argc - 1], O_WRONLY | O_CREAT);
	while (i < g->nbr_fork)
	{
		ft_pipe(i, g);
		ft_fork(i, g);
		if (g->pids[i] == 0)
			ft_child(i, env, g);
		ft_parent(i, g);
		i++;
	}
	g->lst = head;
	i = 0;
	while (i < g->nbr_fork)
	{
		ft_waitpid(g->pids[i], &status, 0, g);
		i++;
	}
}
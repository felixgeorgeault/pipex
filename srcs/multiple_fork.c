/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:44:26 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/11 19:52:44 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int pos, char **env, t_global *g)
{
	if (pos == 0)
		ft_first_child(pos, env, g);
	else if (pos == g->nbr_fork - 1)
		ft_last_child(pos, env, g);
	else 
	{
		ft_dup2(g->pipefd[pos - 1][0], 0, g);
		close(g->pipefd[pos - 1][0]);
		ft_dup2(g->pipefd[pos][1], 1, g);
		close(g->pipefd[pos][1]);
		execve(g->lst->content[0], g->lst->content, env);
		g->lst = g->lst->next;
	}
}

void	ft_exec(char **env, t_global *g)
{
	int		i;
	t_pipex *head;

	i = 0;
	head = g->lst;
	while (i < g->nbr_fork)
	{
		ft_pipe(i, g);
		ft_fork(i, g);
		if (g->pids[i] == 0)
			ft_child(i, env, g);
		ft_parent_close(i, g);
		i++;
	}
	g->lst = head;
}

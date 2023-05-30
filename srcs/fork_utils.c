/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:37 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/31 01:29:54 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char **envp, t_global *g)
{
	int	success;

	success = execve(g->lst->content[0], g->lst->content, envp);
	if (success == -1)
		ft_error(g, "Execve Crash !\n");
}

void	ft_children_close(int pos, t_global *g)
{
	if (pos == 0)
	{
		ft_close(&g->pipefd[0][0], g);
		ft_close(&g->outfile, g);
	}
	else if (pos == g->nbr_fork - 1)
		ft_close(&g->infile, g);
	else
	{
		ft_close(&g->pipefd[pos][0], g);
		ft_close(&g->infile, g);
		ft_close(&g->outfile, g);
	}
}

void	ft_parent_close(int pos, t_global *g)
{
	if (pos == 0)
	{
		ft_close(&g->infile, g);
		ft_close(&g->pipefd[0][1], g);
	}
	else if (pos == g->nbr_fork - 1)
	{
		ft_close(&g->pipefd[pos - 1][0], g);
		ft_close(&g->outfile, g);
	}
	else
	{
		ft_close(&g->pipefd[pos - 1][0], g);
		ft_close(&g->pipefd[pos][1], g);
	}
}

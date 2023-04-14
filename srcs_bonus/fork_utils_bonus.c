/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:37 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/14 15:42:41 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_middle_child(int pos, t_global *g)
{
	int	i;

	i = 0;
	while (i < pos - 2)
	{
		ft_close(&g->pipefd[i][0], g);
		ft_close(&g->pipefd[i][1], g);
		i++;
	}
	ft_close(&g->outfile, g);
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

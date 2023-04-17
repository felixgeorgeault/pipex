/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:37 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/14 17:46:09 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

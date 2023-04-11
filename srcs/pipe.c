/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:57:09 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/11 18:24:26 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	*ft_createmini_tab(t_global *g)
{
	int	*tab;

	tab = NULL;
	tab = malloc(sizeof(int) * 2);
	if (!tab)
		ft_error(g);
	return (tab);
}

void	ft_createpipe_tab(t_global *g)
{
	int	i;
	int	**tab;

	i = 0;
	tab = NULL;
	tab = malloc(sizeof(int *) * (g->nbr_pipe));
	if (!tab)
		ft_error(g);
	while (i < g->nbr_pipe)
	{
		tab[i] = ft_createmini_tab(g);
		i++;
	}
	g->pipefd = tab;
}

void	ft_pipe(int pos, t_global *g)
{
	if (pos != g->nbr_fork - 1)
	{
		if (pipe(g->pipefd[pos]) == -1)
			ft_error(g);
	}
}

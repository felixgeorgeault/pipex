/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:56 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/12 15:08:56 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_pipefds(t_global *g)
{
	int	i;

	i = 0;
	if (!g->pipefd)
		return ;
	while (i < g->nbr_pipe)
	{
		if (g->pipefd[i])
			free(g->pipefd[i]);
		i++;
	}
	free(g->pipefd);
}

void	ft_free_pids(t_global *g)
{
	if (!g->pids)
		return ;
	free(g->pids);
}

void	ft_error(t_global *g, const char *custom_perror)
{
	ft_free_tab(g->paths);
	ft_free_pipefds(g);
	ft_free_pids(g);
	ft_lstclear_pipex(&g->lst);
	ft_putstr_fd("Error\n", 2);
	perror(custom_perror);
	exit(EXIT_FAILURE);
}

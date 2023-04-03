/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:56 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/03 19:45:51 by fgeorgea         ###   ########.fr       */
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

void	ft_error(t_global *g)
{
	if (g->paths)
		ft_free_tab(g->paths);
	if (g->cmd1)
		ft_free_tab(g->cmd1);
	if (g->cmd2)
		ft_free_tab(g->cmd2);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
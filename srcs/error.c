/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:56 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/05 18:17:38 by fgeorgea         ###   ########.fr       */
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
	ft_free_tab(g->paths);
	ft_lstclear_pipex(&g->lst);
	ft_putstr_fd("Error\n", 2);
	perror(NULL);
	exit(EXIT_FAILURE);
}
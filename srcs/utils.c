/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:29 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/12 15:20:12 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_tablen(char **tab, t_global *g)
{
	int	i;

	i = 0;
	if (!tab)
		ft_error(g, "Failed to get the size of the array -> ft_tablen function\n");
	while (tab[i])
		i++;
	return (i);
}

void	ft_close(int fd, t_global *g)
{
	if (close(fd) == -1)
		ft_error(g, CLOSE_ERR);
}

void	ft_dup2(int file1, int file2, t_global *g)
{
	int	success;

	success = dup2(file1, file2);
	if (success == -1)
		ft_error(g, DUP2_ERR);
}

void	ft_waitpid(t_global *g)
{
	int	i;
	int	success;
	int	status;

	i = 0;
	while (i < g->nbr_fork)
	{
		success = waitpid(g->pids[i], &status, 0);
		if (success == -1)
			ft_error(g, WAITPID_ERR);
		i++;
	}
}

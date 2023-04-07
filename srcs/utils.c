/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:29 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:47 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_tablen(char **tab, t_global *g)
{
	int	i;

	i = 0;
	if (!tab)
		ft_error(g);
	while (tab[i])
		i++;
	return (i);
}

void	ft_close(int fd, t_global *g)
{
	if (close(fd) == -1)
		ft_error(g);
}

void	ft_dup2(int file1, int file2, t_global *g)
{
	int	success;

	success = 0;
	success = dup2(file1, file2);
	if (success == -1)
		ft_error(g);
}

void	ft_waitpid(pid_t pid, int *status, int options, t_global *g)
{
	int	success;

	success = 0;
	success = waitpid(pid, status, options);
	if (success == -1)
		ft_error(g);
}

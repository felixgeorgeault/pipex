/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:29 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/06 16:33:26 by fgeorgea         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:29 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/05 16:46:11 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
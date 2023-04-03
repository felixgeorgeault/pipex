/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:11:34 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/03 12:34:09 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_paths(char **env, t_global *g)
{
	int	i;

	i = 0;
	while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
		i++;
	if (ft_strncmp(env[i], "PATH=", 5) != 0)
		ft_error(g);
	g->paths = ft_split(&env[i][5], ':');
	if (!g->paths)
		ft_error(g);
	ft_print_tab(g->paths);
}

void	ft_init_struct(int argc, char **argv, char **env, t_global *g)
{
	g->argv = NULL;
	g->paths = NULL;
	g->argc = argc - 1;
	ft_init_paths(env, g);
	(void)argv; // get rid of this later
	
}
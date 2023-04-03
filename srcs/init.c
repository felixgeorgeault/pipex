/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:11:34 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/03 20:16:36 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_add_slash(t_global *g)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (g->paths[i])
	{
		tmp = ft_strjoin(g->paths[i], "/");
		free(g->paths[i]);
		g->paths[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}

static void	ft_init_paths(char **env, t_global *g)
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
}

static void	ft_init_cmds(char **argv, t_global *g)
{
	g->cmd1 = ft_split(argv[2], ' ');
	if (!g->cmd1)
		ft_error(g);
	g->cmd2 = ft_split(argv[3], ' ');
	if (!g->cmd2)
		ft_error(g);
}

void	ft_init_struct(int argc, char **argv, char **env, t_global *g)
{
	g->paths = NULL;
	g->cmd1 = NULL;
	g->cmd2 = NULL;
	g->argc = argc - 1;
	g->nbr_cmds = g->argc - 2;
	ft_init_paths(env, g);
	ft_add_slash(g);
	ft_init_cmds(argv, g);
}
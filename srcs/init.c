/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:11:34 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/11 18:17:35 by fgeorgea         ###   ########.fr       */
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
	g->nbr_paths = ft_tablen(g->paths, g);
}

static void	ft_init_cmds(char **argv, t_global *g)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	while (i < g->nbr_cmds)
	{
		tmp = ft_split(argv[i + 2], ' ');
		ft_lstadd_back_pipex(&g->lst, ft_lstnew_pipex(tmp));
		i++;
	}
}

void	ft_init_struct(int argc, char **argv, char **env, t_global *g)
{
	g->paths = NULL;
	g->lst = NULL;
	g->pids = NULL;
	g->pipefd = NULL;
	g->argc = argc;
	g->nbr_cmds = g->argc - 3;
	g->nbr_pipe = g->nbr_cmds - 1;
	g->nbr_fork = g->nbr_cmds;
	g->infile = open(argv[1], O_RDONLY);
	if (g->infile == -1)
		ft_error(g);
	g->outfile = open(argv[g->argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (g->outfile == -1)
		ft_error(g);
	ft_init_paths(env, g);
	ft_add_slash(g);
	ft_init_cmds(argv, g);
	ft_createpipe_tab(g);
	ft_createfork_tab(g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:11:34 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/12 17:59:19 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		ft_error(g, "Did not find any PATH line in the env\n");
	g->paths = ft_split(&env[i][5], ':');
	if (!g->paths)
		ft_error(g, "Failed to create paths array with split\n");
	g->nbr_paths = ft_tablen(g->paths, g);
}

static void	ft_init_cmds(char **argv, t_global *g)
{
	int		i;
	int		cmd_offset;
	char	**tmp;

	i = 0;
	cmd_offset = 2;
	tmp = NULL;
	if (g->is_heredoc)
		cmd_offset = 3;
	while (i < g->nbr_cmds)
	{
		tmp = ft_split(argv[i + cmd_offset], ' ');
		ft_lstadd_back_pipex(&g->lst, ft_lstnew_pipex(tmp));
		i++;
	}
}

void	ft_init_struct(int argc, char **argv, char **env, t_global *g)
{
	g->is_heredoc = 0;
	ft_check_here_doc(argc, argv, g);
	ft_init_struct_vars(argc, argv, g);
	ft_init_paths(env, g);
	ft_add_slash(g);
	ft_init_cmds(argv, g);
	ft_createpipe_tab(g);
	ft_createfork_tab(g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:43:04 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/04 16:57:03 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	does_cmd_exist(char *str)
{
	if (access(str, F_OK | X_OK) != -1)
		return (1);
	else
		return (0);
}

static void	put_path_cmd(char **cmd, t_global *g)
{
	int		i;
	char	*tmp;
	
	i = 0;
	tmp = NULL;
	while (g->paths[i])
	{
		tmp = ft_strjoin(g->paths[i], *cmd);
		if (does_cmd_exist(tmp))
		{
			*cmd = ft_strdup(tmp);
			free(tmp);
			break ;
		}
		free(tmp);
		if (i == g->nbr_paths - 1)
			ft_error(g);
		i++;
	}
}

static void	ft_fill_cmds(t_global *g)
{
	t_pipex *first;

	first = g->lst;
	while (g->lst)
	{
		if (!does_cmd_exist(g->lst->content[0]))
			put_path_cmd(&g->lst->content[0], g);
		g->lst = g->lst->next;
	}
	g->lst = first;
}

void	ft_parse_cmds(t_global *g)
{
	ft_fill_cmds(g);
	ft_print_lst(g);
}
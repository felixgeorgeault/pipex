/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:44:26 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/31 01:28:14 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int pos, char **env, t_global *g)
{
	ft_children_close(pos, g);
	if (pos == 0)
		ft_first_child(g);
	else if (pos == g->nbr_fork - 1)
		ft_last_child(pos, g);
	else
		ft_middle_child(pos, g);
	put_path_cmd(&g->lst->content[0], g);
	if (!does_cmd_exist(g->lst->content[0]))
		exit(127);
	ft_execve(env, g);
}

void	ft_exec(char **env, t_global *g)
{
	int		i;
	t_pipex	*lst;

	i = 0;
	lst = g->lst;
	while (i < g->nbr_fork)
	{
		ft_pipe(i, g);
		ft_fork(i, g);
		if (g->pids[i] == 0)
			ft_child(i, env, g);
		ft_parent_close(i, g);
		lst = lst->next;
		i++;
	}
}

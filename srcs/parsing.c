/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:43:04 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/03 20:32:23 by fgeorgea         ###   ########.fr       */
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

static int	ft_check_cmd(char **str, int j, t_global *g)
{
	char	*tmp;
	int		tablen;
	
	tmp = NULL;
	if (does_cmd_exist(*str))
		return (1);
	tmp = ft_strjoin(g->paths[j], *str);
	if (does_cmd_exist(tmp))
	{
		free(*str);
		*str = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	free(tmp);
	tablen = 0;
	while (g->paths[tablen])
		tablen++;
	if (j < tablen - 1)
		return (0);
	return (-1);
}

static void	ft_fill_cmds(t_global *g)
{
	int	i;
	int	res;
	
	i = 0;
	res = -10;
	while (g->paths[i])
	{
		res = ft_check_cmd(&g->cmd1[0], i, g);
		if (res == 1)
			break ;
		else if (res == -1)
			ft_error(g);
		else
			i++;
	}
	i = 0;
	res = -10;
	while (g->paths[i])
	{
		res = ft_check_cmd(&g->cmd2[0], i, g);
		if (res == 1)
			break ;
		else if (res == -1)
			ft_error(g);
		else
			i++;
	}
}

void	ft_parse_cmds(t_global *g)
{
	ft_fill_cmds(g);
	ft_print_all(g);
}
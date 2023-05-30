/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:43:04 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/31 01:24:38 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	does_cmd_exist(char *str)
{
	if (access(str, F_OK | X_OK) != -1)
		return (1);
	else
		return (0);
}

void	put_path_cmd(char **cmd, t_global *g)
{
	int		i;
	char	*new_str;

	i = 0;
	while (g->paths[i])
	{
		new_str = ft_strjoin(g->paths[i], *cmd);
		if (!new_str)
			ft_error(g, "MALLOC CRASH !\n");
		if (does_cmd_exist(new_str))
		{
			free(*cmd);
			*cmd = new_str;
			return ;
		}
		free(new_str);
		if (i == g->nbr_paths - 1)
			ft_error(g, "Command was not found\n");
		i++;
	}
}

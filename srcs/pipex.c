/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:32 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/31 01:24:26 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_global	g;

	if (argc >= 5)
	{
		ft_init_struct(argc, argv, env, &g);
		if (g.is_heredoc)
			ft_here_doc(&g);
		ft_exec(env, &g);
		ft_waitpid(&g);
		ft_free_array(g.paths);
		free(g.pids);
		ft_free_int_array(g.pipefd, g.nbr_pipe);
		ft_lstclear_pipex(&g.lst);
		ft_unlink_tmp();
	}
	return (0);
}

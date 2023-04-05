/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/05 15:57:04 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_fork(t_global *g, char **argv, char **env)
{
	pid_t	pid;
	int		file1;
	int		file2;
	int		status;
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY);
	pipe(g->pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(g->pipefd[1], 1);
		dup2(file1, 0);
		close(g->pipefd[0]);
		close(file1);
		execve(g->lst->content[0], g->lst->content, env);
	}
	waitpid(pid, &status, 0);
	dup2(file2, 1);
	dup2(g->pipefd[0], 0);
	close(g->pipefd[1]);
	close(file2);
	execve(g->lst->next->content[0], g->lst->next->content, env);
}

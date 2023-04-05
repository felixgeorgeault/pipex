/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/05 18:04:24 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	ft_child(int file1, char **env, t_global *g)
{
	int	success;

	success = dup2(g->pipefd[1], 1);
	if (success == -1)
		ft_error(g);
	success = dup2(file1, 0);
	if (success == -1)
		ft_error(g);
	close(g->pipefd[0]);
	close(file1);
	success = execve(g->lst->content[0], g->lst->content, env);
	if (success == -1)
		ft_error(g);
}

void static	ft_parent(int file2, char **env, t_global *g, pid_t pid)
{
	int	status;
	int	success;

	waitpid(pid, &status, 0);
	success = dup2(file2, 1);
	if (success == -1)
		ft_error(g);
	success = dup2(g->pipefd[0], 0);
	if (success == -1)
		ft_error(g);
	close(g->pipefd[1]);
	close(file2);
	success = execve(g->lst->next->content[0], g->lst->next->content, env);
	if (success == -1)
		ft_error(g);
}

void	ft_init_fork(t_global *g, char **argv, char **env)
{
	pid_t	pid;
	int		file1;
	int		file2;
	int		pipe_status;
	
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY);
	pipe_status = pipe(g->pipefd);
	if (pipe_status == -1)
		ft_error(g);
	pid = fork();
	if (pid == -1)
		ft_error(g);
	if (pid == 0)
		ft_child(file1, env, g);
	ft_parent(file2, env, g, pid);
}

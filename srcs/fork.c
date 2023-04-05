/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/05 18:21:59 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	ft_child(int file1, char **env, t_global *g)
{
	if (dup2(g->pipefd[1], 1) == -1)
		ft_error(g);
	if (dup2(file1, 0) == -1)
		ft_error(g);
	close(g->pipefd[0]);
	close(file1);
	if (execve(g->lst->content[0], g->lst->content, env) == -1)
		ft_error(g);
}

void static	ft_parent(int file2, char **env, t_global *g, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (dup2(file2, 1) == -1)
		ft_error(g);
	if (dup2(g->pipefd[0], 0) == -1)
		ft_error(g);
	close(g->pipefd[1]);
	close(file2);
	if (execve(g->lst->next->content[0], g->lst->next->content, env) == -1)
		ft_error(g);
}

void	ft_init_fork(t_global *g, char **argv, char **env)
{
	pid_t	pid;
	int		file1;
	int		file2;
	
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		ft_error(g);
	file2 = open(argv[g->argc - 1], O_WRONLY);
	if (file2 == -1)
		ft_error(g);
	if (pipe(g->pipefd) == -1)
		ft_error(g);
	pid = fork();
	if (pid == -1)
		ft_error(g);
	if (pid == 0)
		ft_child(file1, env, g);
	ft_parent(file2, env, g, pid);
}

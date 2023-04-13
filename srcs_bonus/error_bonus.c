/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:56 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/13 15:05:07 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(t_global *g, const char *custom_perror)
{
	ft_free_array(g->paths);
	free(g->pids);
	ft_free_int_array(g->pipefd, g->nbr_pipe);
	ft_lstclear_pipex(&g->lst);
	ft_unlink_tmp();
	ft_putstr_fd("Error\n", 2);
	perror(custom_perror);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:55 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/07 17:15:37 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../include/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
/**************************************************************/
/*********************      STRUCTS    ************************/
/**************************************************************/

typedef struct s_pipex
{
	char			**content;
	struct s_pipex	*next;
}		t_pipex;

typedef struct s_global
{
	int		argc;
	int		nbr_cmds;
	int		nbr_pipe;
	int		nbr_fork;
	int		nbr_paths;
	int		file1;
	int		file2;
	char	**paths;
	int		**pipefd;
	pid_t	*pids;
	t_pipex	*lst;
}		t_global;

/**************************************************************/
/*********************    FUNCTIONS    ************************/
/**************************************************************/

// INIT.C
void	ft_init_struct(int argc, char **argv, char **end, t_global *g);

// ERROR.C
void	ft_free_tab(char **tab);
void	ft_error(t_global *g);
void	ft_free_pipefds(t_global *g);
void	ft_free_pids(t_global *g);

// DEBUG.C GET RID OF THAT SHIIIIIIIiiiikaldsjfaklsdfjalskdfjaslnkfjaelskjrlnaekwjakwjrklwjerklwjkrnv !!!!!
void	ft_print_tab(char **tab);
void	ft_print_fds(t_global *g);
void	ft_print_lst(t_global *g);
void	ft_print_pipefds(t_global *g);

// PARSING.C
void	ft_parse_cmds(t_global *g);

// CHAINED_LIST.C
void	ft_lstadd_back_pipex(t_pipex **lst, t_pipex *new);
t_pipex	*ft_lstlast_pipex(t_pipex *lst);
void	ft_lstclear_pipex(t_pipex **lst);
int		ft_lstsize_pipex(t_pipex **lst);
t_pipex	*ft_lstnew_pipex(char **content);

// UTILS.C
int		ft_tablen(char **tab, t_global *g);
void	ft_close(int fd, t_global *g);
void	ft_dup2(int file1, int file2, t_global *g);
void	ft_waitpid(pid_t pid, int *status, int options, t_global *g);

// FORK.C
void	ft_init_fork(t_global *g, char **argv, char **env);
void	ft_createfork_tab(t_global *g);
void	ft_fork(int pos, t_global *g);

// MULTIPLE_FORK.C
void	ft_exec(char **argv, char **env, t_global *g);

// PIPE.C
void	ft_pipe(int pos, t_global *g);
void	ft_createpipe_tab(t_global *g);

#endif
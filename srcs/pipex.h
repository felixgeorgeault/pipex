/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:55 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/04 15:22:55 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include "../include/libft/libft.h"
# include <fcntl.h>
/**************************************************************/
/*********************      STRUCTS    ************************/
/**************************************************************/

typedef struct s_pipex
{
	char			**content;
	struct s_pipex	*next;
}		t_pipex;

typedef struct	s_global
{
        int		argc;
		int		nbr_cmds;
		char	**paths;
		char	**cmd1;
		char	**cmd2;
		int		pipefd[2];
		t_pipex *lst;
		
}		t_global;

/**************************************************************/
/*********************    FUNCTIONS    ************************/
/**************************************************************/

// INIT.C
void	ft_init_struct(int argc, char **argv, char **end, t_global *g);

// ERROR.C
void	ft_free_tab(char **tab);
void	ft_error(t_global *g);

// DEBUG.C GET RID OF THAT SHIIIIIIIiiiikaldsjfaklsdfjalskdfjaslnkfjaelskjrlnaekwjakwjrklwjerklwjkrnv !!!!!
void	ft_print_tab(char **tab);
void	ft_print_fds(t_global *g);
void	ft_print_all(t_global *g);
void	ft_print_lst(t_global *g);

// PARSING.C
void	ft_parse_cmds(t_global *g);

// PIPE.C
void	ft_init_pipe(t_global *g);

// CHAINED_LIST.C
void	ft_lstadd_back_pipex(t_pipex **lst, t_pipex *new);
t_pipex	*ft_lstlast_pipex(t_pipex *lst);
void	ft_lstclear_pipex(t_pipex **lst);
int		ft_lstsize_pipex(t_pipex **lst);
t_pipex	*ft_lstnew_pipex(char **content);

#endif
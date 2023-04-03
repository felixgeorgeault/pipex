/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:55:55 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/24 17:35:24 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include "../include/libft/libft.h"
/**************************************************************/
/*********************      STRUCTS    ************************/
/**************************************************************/

typedef struct	s_global
{
        int		argc;
        char	**argv;
		char	**paths;
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

#endif
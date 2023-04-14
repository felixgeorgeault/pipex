/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:09:27 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/14 17:18:31 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_set_lst_head(t_pipex **lst)
{
	if (!lst || !*lst)
		return ;
	while ((*lst)->previous)
		*lst = (*lst)->previous;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:37:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/31 01:19:03 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstadd_back_pipex(t_pipex **lst, t_pipex *new)
{
	t_pipex	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		last = ft_lstlast_pipex(*lst);
		last->next = new;
	}
}

t_pipex	*ft_lstlast_pipex(t_pipex *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear_pipex(t_pipex **lst)
{
	t_pipex	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_free_array(tmp->content);
		free(tmp);
	}
}

t_pipex	*ft_lstnew_pipex(char **content, t_global *g)
{
	t_pipex	*list;

	list = malloc(sizeof(t_pipex));
	if (!list)
	{
		ft_free_array(content);
		ft_error(g, "Failed to create new struct in chained list\n");
	}
	list->content = content;
	list->next = NULL;
	return (list);
}

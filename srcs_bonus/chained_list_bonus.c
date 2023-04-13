/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:37:54 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/13 13:37:43 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_free_array(tmp->content);
		free(tmp);
	}
}

int	ft_lstsize_pipex(t_pipex **lst)
{
	t_pipex	*first;
	size_t	i;

	first = *lst;
	i = 1;
	if (!lst || !*lst)
		return (0);
	while (*lst)
	{
		*lst = (*lst)->next;
		i++;
	}
	*lst = first;
	return (i);
}

t_pipex	*ft_lstnew_pipex(char **content)
{
	t_pipex	*list;

	list = malloc(sizeof(t_pipex));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

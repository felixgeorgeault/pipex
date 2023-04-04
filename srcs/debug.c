#include "pipex.h"

void	ft_print_all(t_global *g)
{
	ft_print_tab(g->cmd1);
	ft_print_tab(g->cmd2);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_print_fds(t_global *g)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		ft_printf("%d\n", g->pipefd[i]);
		i++;
	}
}

void	ft_print_lst(t_global *g)
{
	if (!g->lst)
		return ;
	t_pipex	*first;

	first = g->lst;
	while (g->lst->next)
	{
		ft_printf("[%s %s]\n", g->lst->content[0], g->lst->content[1]);
		ft_printf("----------\n");
		g->lst = g->lst->next;
	}
	ft_printf("[%s %s]\n", g->lst->content[0], g->lst->content[1]);
	ft_printf("----------\n");
	g->lst = first;
}
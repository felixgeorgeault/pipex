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
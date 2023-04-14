/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:00:32 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/14 16:34:03 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_exit_here_doc(char *str, int end_token_len, t_global *g)
{
	if (ft_strncmp(str, g->end_token, end_token_len) == 0)
		return (1);
	return (0);
}

void	ft_here_doc(t_global *g)
{
	char	*str;
	int		end_token_len;

	end_token_len = ft_strlen(g->end_token);
	str = get_next_line(STDIN_FILENO);
	while (*str)
	{
		if (ft_exit_here_doc(str, end_token_len, g))
			break ;
		ft_putstr_fd(str, g->infile);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	free(str);
	ft_close(&g->infile, g);
	g->infile = open(TMP_FILE, O_RDONLY, 0644);
	if (g->infile == -1)
		ft_error(g, "Failed to open infile\n");
}

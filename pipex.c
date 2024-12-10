/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/10 18:12:32 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		ft_clean_up(t_process **pipex);
void		ft_error(t_process ***pipex, char **string);
static void	ft_create_struct(t_process **pipex, char *args[]);

int	main(int argc, char *argv[])
{
	t_process	*pipex;

	if (argc != 5)
		exit(EXIT_FAILURE);
	ft_create_struct(&pipex, argv);
	if (pipex->child_pid == 0)
		ft_child_process(&pipex);
	else//TODO: check if it still works without the else clause
	{
		waitpid(pipex->child_pid, NULL, 0);
		ft_parent_process(&pipex);
	}
	ft_clean_up(&pipex);
	exit(EXIT_SUCCESS);
}

void	ft_clean_up(t_process **pipex)
{
	int			i;
	t_process	*clean;

	clean = *pipex;
	ft_lstclear(&(clean->execve_argv), free);
	free(clean);
}

void	ft_error(t_process ***pipex, char **string)
{
	perror(strerror(errno));
	if (**pipex)
		ft_clean_up(*pipex);
	if (string)
		free(string);
	exit(EXIT_FAILURE);
}

static void	ft_create_struct(t_process **pipex, char *args[])
{
	int	c;

	*pipex = ft_calloc(1, sizeof(t_process));
	if (!*pipex)
		ft_error(&pipex, NULL);
	c = 0;
	while (c < 4)
	{
		(*pipex)->args[c] = ft_strtrim(args[c + 1], TRIM_SET);
		c++;
	}
	c = pipe((*pipex)->pipe);
	if (c == -1)
		ft_error(&pipex, NULL);
	(*pipex)->child_pid = (int) fork();
	if ((*pipex)->child_pid == -1)
		ft_error(&pipex, NULL);
}

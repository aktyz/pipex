/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 16:16:24 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_up(t_pipex **pipex);
void	ft_error(t_pipex ***pipex);
static void	ft_create_struct(t_pipex **pipex, char *args[]);

int	main(int argc, char *argv[])
{
	t_pipex	*pipex;

	if (argc != 5)
		exit(EXIT_FAILURE);
	ft_create_struct(&pipex, argv);
	if (pipex->child_pid == 0)
		ft_child_process(&pipex);
	else
		ft_parent_process(&pipex);
	ft_clean_up(&pipex);
	exit(EXIT_SUCCESS);
}

void	ft_clean_up(t_pipex **pipex)
{
	int		i;
	char	*arg;
	t_pipex	*clean;

	clean = *pipex;
	if (clean->args[0])
	{
		i = 0;
		while (i < 4)
		{
			arg = clean->args[i];
			free(arg);
			clean->args[i] = NULL;
			i++;
		}
	}
	free(clean);
}

void	ft_error(t_pipex ***pipex)
{
	perror(strerror(errno));
	if (**pipex)
		ft_clean_up(*pipex);
	exit(EXIT_FAILURE);
}

static void	ft_create_struct(t_pipex **pipex, char *args[])
{
	int	c;

	*pipex = ft_calloc(1, sizeof(t_pipex));
	if (!*pipex)
		ft_error(&pipex);
	c = 0;
	while (c < 4)
	{
		(*pipex)->args[c] = ft_strtrim(args[c + 1], TRIM_SET);
		c++;
	}
	c = pipe((*pipex)->pipe_fd);
	if (c == -1)
		ft_error(&pipex);
	(*pipex)->child_pid = (int) fork();
	if ((*pipex)->child_pid == -1)
		ft_error(&pipex);
}

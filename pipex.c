/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 08:42:48 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		ft_clean_up(t_pipex **pipex);
void		ft_error(t_pipex ***pipex, char **string);
static void	ft_create_struct(t_pipex **pipex, char *args[]);
static void	ft_clean_mem(char **args[]);

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
	t_pipex	*clean;

	clean = *pipex;
	ft_clean_mem((char ***) &clean->args);
	ft_clean_mem((char ***) &clean->execve_argv);
	free(clean);
}

void	ft_error(t_pipex ***pipex, char **string)
{
	perror(strerror(errno));
	if (**pipex)
		ft_clean_up(*pipex);
	if (string)
		free(string);
	exit(EXIT_FAILURE);
}

static void	ft_create_struct(t_pipex **pipex, char *args[])
{
	int	c;

	*pipex = ft_calloc(1, sizeof(t_pipex));
	if (!*pipex)
		ft_error(&pipex, NULL);
	c = 0;
	while (c < 4)
	{
		(*pipex)->args[c] = ft_strtrim(args[c + 1], TRIM_SET);
		c++;
	}
	c = pipe((*pipex)->pipe_fd);
	if (c == -1)
		ft_error(&pipex, NULL);
	(*pipex)->child_pid = (int) fork();
	if ((*pipex)->child_pid == -1)
		ft_error(&pipex, NULL);
}

static void	ft_clean_mem(char **args[])
{
	char	**arg;
	int		i;

	if (args == NULL || *args == NULL)
		return ;
	arg = *args;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(*args);
	*args = NULL;
}

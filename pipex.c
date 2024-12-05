/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 14:48:46 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_clean_up(t_pipex **pipex);
static void	ft_create_struct(t_pipex **pipex, char *args[]);
static void	ft_error(t_pipex ***pipex);

int	main(int argc, char *argv[])
{
	t_pipex	*pipex;
	char	buf[13];

	if (argc != 5)
		exit(EXIT_FAILURE);
	ft_create_struct(&pipex, argv);
	if (pipex->child_pid == 0)
	{
		ft_printf("I am child - executing first command on input file\n");
		close(pipex->pipe_fd[0]);
		write(pipex->pipe_fd[1], "Hello parent!\n", 13);
		close(pipex->pipe_fd[1]);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		read(pipex->pipe_fd[0], buf, 13);
		close(pipex->pipe_fd[0]);
		ft_printf("I am parent - executing second command, saving to output\n");
		ft_printf("Message from my child: \"%s\"\n", buf);
	}
	ft_clean_up(&pipex);
	exit(EXIT_SUCCESS);
}

static void	ft_clean_up(t_pipex **pipex)
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
	(*pipex)->child_pid = (long) fork();
	if ((*pipex)->child_pid == -1)
		ft_error(&pipex);
}

static void	ft_error(t_pipex ***pipex)
{
	perror(strerror(errno));
	if (**pipex)
		ft_clean_up(*pipex);
	exit(EXIT_FAILURE);
}

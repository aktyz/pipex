/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 13:05:13 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_clean_up(t_pipex **pipex);
void	ft_destroy_string(char *str);

int	main(int argc, char *argv[])
{
	t_pipex	*pipex;
	int		c;
	char	buf[13];

	if (argc != 5)
		exit(EXIT_FAILURE);
	c = 0;
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
	{
		ft_printf("Error with ft_calloc\n");
		pipex_clean_up(&pipex);
		exit(EXIT_FAILURE);
	}
	while(c < argc - 1)
	{
		pipex->args[c] = ft_strtrim(argv[c + 1], TRIM_SET);
		c++;
	}
	c = pipe(pipex->pipe_fd);
	if (c == -1)
	{
		ft_printf("Error with pipe\n");
		pipex_clean_up(&pipex);
		exit(EXIT_FAILURE);
	}
	pipex->child_pid = (long) fork();
	if (pipex->child_pid == -1)
	{
		ft_printf("Error with fork\n");
		pipex_clean_up(&pipex);
		exit(EXIT_FAILURE);
	}
	if (pipex->child_pid == 0)
	{
		ft_printf("I am child - executing first command on input file\n");
		close(pipex->pipe_fd[0]);
		write(pipex->pipe_fd[1], "Hello parent!", 13);
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
	pipex_clean_up(&pipex);
	exit(EXIT_SUCCESS);
}

void	pipex_clean_up(t_pipex **pipex)
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

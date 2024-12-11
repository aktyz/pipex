/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/11 19:18:24 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		ft_clean_up(t_process **pipex);
void		ft_error(t_process ***pipex, char **string);
static void	ft_create_struct(t_process **pipex, char *args[]);
static void	ft_delete_lst_node(t_list *node);

int	main(int argc, char *argv[])
{
	t_process	*pipex;

	if (argc != 5)
		exit(EXIT_FAILURE);
	ft_create_struct(&pipex, argv);
	if (pipex->child_pid == 0)
		ft_child_process(&pipex);
	waitpid(pipex->child_pid, NULL, 0);
	ft_parent_process(&pipex);
	ft_clean_up(&pipex);
	exit(EXIT_SUCCESS);
}

void	ft_clean_up(t_process **pipex)
{
	int			i;
	t_process	*clean;
	t_list		*node;

	clean = *pipex;
	node = clean->execve_argv;
	if (node)
	{
		i = clean->execve_argc;
		while (i > 0)
		{
			node = clean->execve_argv->next;
			ft_delete_lst_node(clean->execve_argv);
			clean->execve_argv = node;
			i--;
		}
	}
	if (clean->args[0])
	{
		i = 0;
		while (i < 4)
		{
			if (clean->args[i])
				free(clean->args[i]);
			i++;
		}
	}
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

static void	ft_delete_lst_node(t_list *node)
{
	if (node->content)
		free(node->content);
	if (node)
		free(node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:23 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/04 17:50:04 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
#include <stdlib.h> // exit()

# define TRIM_SET " \t\n"

typedef struct s_pipex
{
	char	*args[4]; //we will store our trimmed args here
	int		*pipe[2]; //we will store our pipe here
	int		parent_id; //pid of the parent
} t_pipex;


#endif
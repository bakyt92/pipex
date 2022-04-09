/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:44:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/09 20:44:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/* for OPEN FUNCTION */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_list {
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int 	input_file_fd;
	int 	output_file_fd;
	char	**path_command;
	char	**args_command;
	char	*command;
}	t_list;

void	ft_error(char *str);


#endif

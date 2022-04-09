
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list {
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int 	input_file;
	int 	output_file;
	char	**path_command;
	char	**args_command;
	char	*command;
}	t_list;

void	ft_error(char *str);


#endif
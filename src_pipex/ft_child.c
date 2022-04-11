#include "../pipex.h"

char 	*ft_check_access(char **path_command, char *command)
{
	char *tmp;
	char *tmp_command;

	while(*path_command)
	{
		tmp = ft_strjoin(*path_command, "/");
		tmp_command = ft_strjoin(tmp, command);
		free(tmp);
		if (access(tmp_command, X_OK) == 0)
			return (tmp_command);
		free(tmp_command);
		path_command++;
	}
	return(NULL);
}
/*
void	ft_first_child(t_list pipex, char **argv, char **envp)
{
	if (pipex.pid1 != 0)
		return;
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.input_file_fd, 0);




}

void	ft_second_child(t_list pipex, char **argv, char **envp)
{
	if (pipex.pid1 != 0)
		return;
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.output_file_fd, 1);
	pipex.args_command = ft_split(argv[3], ' ');
	pipex.command = ft_check_access(pipex.path_command, pipex.command);
	if (!pipex.command)
	{
		ft_free_child(&pipex);
		write(2, "CMD NOT FOUND", 13);
		exit(1);
	}
	execve(pipex.command, pipex.args_command, envp);
}
 */
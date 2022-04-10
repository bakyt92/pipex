#include "../pipex.h"

void	ft_free_parent(t_list *pipex)
{
	int i;

	i = 0;
	close(pipex->input_file_fd);
	close(pipex->output_file_fd);
	while (pipex->path_command[i])
	{
		free(pipex->path_command[i]);
		i++;
	}
	free(pipex->path_command);
}

void	ft_free_child(t_list *pipex)
{
	int i;

	i = 0;
	while(pipex->args_command[i])
	{
		free(pipex->args_command[i]);
		i++;
	}
	free(pipex->args_command);
	free(pipex->command);
}
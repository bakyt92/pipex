/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:44:43 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/11 20:38:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_func(char *argv, char **envp, t_list *pipex)
{
	if (!argv[0])
	{
		pipex->args_command[0] = ft_strdup("cat");
		pipex->args_command[1] = NULL;
	}
	else
		pipex->args_command = ft_split(argv, ' ');
	pipex->path = ft_find_path(envp);
	pipex->path_command = ft_split(pipex->path, ':');
	pipex->command = ft_check_access(pipex->path_command,
									 pipex->args_command[0]);
	if (!pipex->command)
	{
		ft_free_child(pipex);
		write(2, "CMD NOT FOUND", 13);
		exit(1);
	}
	execve(pipex->command, pipex->args_command, envp);

}

void	ft_last_exec(char *argv, char **envp, t_list *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error("FORK ERROR");
	if (pipex->pid == 0)
		ft_execute_func(argv, envp, pipex);
}

void	ft_close_p(t_list *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	ft_pipex(char *argv, char **envp, t_list *pipex)
{
	waitpid(-1, NULL, 0);
	if (pipe(pipex->tube) < 0)
		ft_error("Pipe function error");
	pipex->pid = fork();
	if (pipex->pid < 0)
		ft_error("FORK ERROR");
	else if (pipex->pid > 0)
	{
		if (close(pipex->tube[1]) == -1)
			ft_error("CLOSE PIPE ERROR");
		if (dup2(pipex->tube[0], 0) == -1)
			ft_error("DUP2 ERROR");
//		waitpid(0, NULL, 0);
	}
	else
	{
		if (close(pipex->tube[0]) == -1)
			ft_error("CLOSE PIPE ERROR");
		if (dup2(pipex->tube[1], 1) == -1)
			ft_error("DUP2 ERROR");
		waitpid(0, NULL, 0);
		ft_execute_func(argv, envp, pipex);

	}
}

int	main(int argc, char **argv, char **envp)
{
	t_list	pipex;

	pipex.args_counter = 2;
	if (argc != 5)
		ft_strerror("Non-valid number of arguments");
	pipex.input_file_fd = open(argv[1], O_RDONLY);
	if (pipex.input_file_fd < 0)
		ft_strerror("Failure to read from infile");
	pipex.output_file_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pipex.output_file_fd < 0)
		ft_strerror("Failure to create outfile");
	if (dup2(pipex.input_file_fd, 0) == -1)
		ft_error("DUP2 ERROR WITH INPUT");
	if (dup2(pipex.output_file_fd, 1) == -1)
		ft_error("DUP2 ERROR WITH OUTPUT");
	while (pipex.args_counter < argc - 2)
		ft_pipex(argv[pipex.args_counter++], envp, &pipex);
	ft_last_exec(argv[pipex.args_counter], envp, &pipex);
	ft_close_p(&pipex);
}

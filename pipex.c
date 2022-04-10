/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:44:43 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/09 20:44:46 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_p(t_list *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	ft_pipex(char **argv, char **envp, t_list *pipex)
{
	if (pipe(pipex->tube) < 0)
		ft_error("Pipe function error");
	pipex->pid = fork();
	if (pipex->pid < 0)
		ft_error("FORK ERROR");
	else if (pipex->pid > 0)
	{
		if (close(pipex->tube[1]) == -1)
			ft_error("CLOSE PIPE ERROR");
		if (dup2(pipex->tube[0], 0))
			ft_error("DUP2 ERROR");
	}
	else
	{
		if (close(pipex->tube[0]) == -1)
			ft_error("CLOSE PIPE ERROR");
		if (dup2(pipex->tube[1], 1))
			ft_error("DUP2 ERROR");
		execute
	}
}

int main(int argc, char **argv, char **envp)
{
	t_list	pipex;

	if (argc != 5)
		ft_error("Non-valid number of arguments");
	pipex.input_file_fd = open(argv[1], O_RDONLY);
	if (pipex.input_file_fd < 0)
		ft_error("Failure to read from infile");
	pipex.output_file_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pipex.output_file_fd < 0)
		ft_error("Failure to create outfile");
	if(dup2(pipex.input_file_fd, 0) == -1)
		ft_error("DUP2 ERROR WITH INPUT");
	if(dup2(pipex.output_file_fd, 1) == -1)
		ft_error("DUP2 ERROR WITH OUTPUT");
	ft_pipex(argv, envp, &pipex);
	ft_last_exec(argv, envp, &pipex);




	pipex.path = ft_find_path(envp);
	pipex.path_command = ft_split(pipex.path, ':');
	pipex.pid1 = fork();
	ft_first_child(pipex, argv, envp);
	if (pipex.pid1 > 0)
		pipex.pid2 = fork();
	ft_second_child(pipex, argv, envp);
	ft_close_p(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	ft_free_parent(&pipex);
}

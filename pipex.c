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

int main(int argc, char **argv, char **envp)
{
	t_list	pipex;

	if (argc != 5)
		ft_error("Non-valid number of arguments");
	pipex.input_file_fd = open(argv[1], O_RDONLY);
	if (pipex.input_file_fd < 0)
		ft_error("Failure to read from infile");
	pipex.output_file_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR);
	if (pipex.output_file_fd < 0)
		ft_error("Failure to create outfile");
}

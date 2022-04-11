/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:39:19 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/04/11 20:39:21 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_find_path(char **envp)
{
	while (*envp != NULL)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			return (*envp + 5);
		envp++;
	}
	ft_error("PATH IS NOT FOUND");
	return (NULL);
}

char	*ft_check_access(char **path_command, char *command)
{
	char	*tmp;
	char	*tmp_command;

	while (*path_command)
	{
		tmp = ft_strjoin(*path_command, "/");
		tmp_command = ft_strjoin(tmp, command);
		free(tmp);
		if (access(tmp_command, X_OK) == 0)
			return (tmp_command);
		free(tmp_command);
		path_command++;
	}
	return (NULL);
}

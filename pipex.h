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
	char 	*path;
	char	**path_command;
	char	**args_command;
	char	*command;
}	t_list;

void	ft_error(char *str);
char	*ft_find_path(char **envp);
void	ft_close_p(t_list *pipex);

/* FREE PROCESSES */

void	ft_free_child(t_list *pipex);
void	ft_free_parent(t_list *pipex);

/* CHILREN PROCESSES */
void	ft_first_child(t_list pipex, char **argv, char **envp);
void	ft_second_child(t_list pipex, char **argv, char **envp);
char 	*ft_check_access(char **path_command, char *command);

/* LIBFT FUNCS */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

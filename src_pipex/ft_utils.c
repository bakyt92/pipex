#include "../pipex.h"

char	*ft_find_path(char **envp)
{
	while (*envp != NULL)
	{
		if (!ft_strncmp("PATH", *envp, 4))
			return (*envp + 5);
		envp++;
	}
	ft_error("PATH IS NOT FOUND");
	return (NULL);
}
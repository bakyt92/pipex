#include "../pipex.h"

static char	*ft_dest(char const *s, char *dest, size_t len, unsigned int start)
{
	size_t	i;
	size_t	pos;

	pos = 0;
	i = 0;
	while (*s != '\0' && pos <= (len + start))
	{
		if (pos >= start && i < len)
		{
			dest[i] = s[pos];
			++i;
		}
		++pos;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= len)
		len = ft_strlen(s);
	if (ft_strlen(s) <= (size_t) start)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_dest(s, dest, len, start);
	return (dest);
}
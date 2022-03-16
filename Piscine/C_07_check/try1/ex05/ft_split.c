#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

char		**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256)))
		return (0);
	while (is_sep(str[i], charset));
		i += 1;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
			return (0);
		while (!is_sep(str[i], charset) && str[i])
			split[k][j++] = str[i++];
		while (str[i] && is_sep(str[i]))
			i += 1;
		split[k][j] = '\0';
		k += 1;
	}
	split[k] = 0;
	return (split);
}

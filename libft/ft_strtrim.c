#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	unsigned int	start;
	unsigned int	size;
	unsigned int	spaces_count;

	if (!s1)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s1);
	spaces_count = ft_strcntfirstchar((char*)s, " \n\t");
	start = spaces_count;
	if (size > spaces_count)
		spaces_count += ft_strcntlastchar((char*)s, " \n\t");
	size -= spaces_count;
	if (!(result = ft_memalloc((size_t)size + 1)))
		return (NULL);
	result = ft_strncpy(result, (char*)s + start, size);
	return (result);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *result;
    unsig
}

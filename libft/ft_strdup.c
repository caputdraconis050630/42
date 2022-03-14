#include "libft.h"

char    *ft_strdup(const char *s1)
{
    int     i;
    char    *dest;
    
    i = 0;
    dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
    if (!dest)
        return (0);
    while (s1[i])
    {
        dest[i] = s1[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}
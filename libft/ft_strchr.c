#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    int index;

    index = 0;
    while (s[index])
    {
        if (s[index] == c)
            return (&s[index]);
    }
    return (0);
}

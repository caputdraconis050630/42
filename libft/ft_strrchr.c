#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int len;

    len = 0;
    while (s[len])
        len += 1;
    len -= 1;
    while (len >= 0)
    {
        if (s[len] == c)
        {
            return (&s[len]);
        }
        len -= 1;
    }
    return (0);
}

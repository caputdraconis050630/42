#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t len)
{
    int     i;
    char    *saddr;

    i = 0;
    saddr = (char *)s;
    while (saddr[i] && i < len)
    {
        if (saddr[i] == c)
            return (&saddr[i]);
        i += 1;
    }
    return (0);
}

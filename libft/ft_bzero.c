#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    unsigned char   *dest;

    dest = (unsigned char *)s;
    while (n > 0)
    {
        *dest = 0;
        s += 1;
        n -= 1;
    }
}

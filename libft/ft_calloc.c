#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *dest;

    dest = (void *)malloc(size * count);
    if (!dest)
        return (0);
    ft_bzero(dest, count);
    return (dest);
}
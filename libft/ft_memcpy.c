#include "libft.h"

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    unsigned char   *dstaddr;
    unsigned char   *srcaddr;

    dstaddr = (unsigned char*)dst;
    srcaddr = (unsigned char*)src;
    if (n == 0)
        return (dst);
    while (n--)
        *dstaddr++ = *srcaddr++;
    return (dst);
}
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char   *s1addr;
    unsigned char   *s2addr;
    int             i;

    s1addr = (unsigned char *)s1;
    s2addr = (unsigned char *)s2;
    i = 0;
    while (s1addr[i] && s2addr[i] && s1addr[i] == s2addr[i] && i < n)
        i += 1;
    if (i == n)
        return (0);
    return (s1addr[i] - s2addr[i]);
}

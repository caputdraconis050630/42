#include "libft.h"

size_t  strlcpy(char * restrict dst, const char *restrict src, size_t dstsize)
{
    int src_len;
    int i;

    i = 0;
    src_len = ft_strlen(src);
    if (dstsize == 0)
        return (src_len);
    while (src[i] != '\0' && i < (dstsize - 1))
    {
        dst[i] = src[i];
        i += 1;
    }
    dst[i] = '\0';
    return (src_len);
}
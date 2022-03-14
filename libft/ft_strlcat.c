#include "libft.h"

size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
    unsigned int    dstlen;
    unsigned int    srclen;
    unsigned int    i;

    dstlen = ft_strlen(dst);
    srclen = ft_strlen(src);
    i = 0;
    if (dstsize == 0)
        return (srclen + dstsize);
    if (dstlen > dstsize)
        return (srclen + dstsize);
    while ((dstlen + i + 1) < dstsize && src[i] != '\0')
    {
        dst[dstlen + i] = src[i];
        i += 1;
    }
    dst[dstlen + i] = '\0';
    return (dstlen + srclen);
}
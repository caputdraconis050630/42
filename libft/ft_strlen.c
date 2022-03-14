#include "libft.h"

int ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s[len])
        len += 1;
    return (len);
}

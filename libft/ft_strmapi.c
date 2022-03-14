char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int     len;
    int     i;
    char    *dst;

    len = 0;
    i = 0;
    while (s[len])
        len += 1;
    dst = (char *)malloc(sizeof(char) * len + 1);
    while (i < len)
    {
        dst[i] = f(i, s[i]);
        i += 1;
    }
    return (dst);
}
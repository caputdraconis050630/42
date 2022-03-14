char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *dst;
    int     i;
    int     srclen;
    int     mallocsize;     

    // s == "hoit"
    // srclen = 4;
    // start = 2;
    // mallocsize = 4 - 2 + 1;
    // return value == "it\0"
    i = 0;
    srclen = ft_strlen(s);
    mallocsize = srclen - start + 1;
    dst = (char *)malloc(sizeof(char) * mallocsize);
    if (!dst || mallocsize <= 1)
        return (0);
    while (s[start + i] && i < len)
    {
        dst[i] = s[start + i];
        i += 1;
    }
    dst[i] = '\0';
    return (dst);
}
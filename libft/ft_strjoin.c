
char    *ft_strjoin(char const *s1, char const *s2)
{
    int     s1_len;
    int     s2_len;
    int     i;
    char    *dest;

    s1_len = 0;
    s2_len = 0;
    i = 0;
    while (s1[s1_len])
        s1_len += 1;
    while (s2[s2_len])
        s2_len += 1;
    dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!dst)
        return (0);
    while (i < s1_len)
    {
        dst[i] = s1_len[i];
        i += 1;
    }
    while (i < s1_len + s2_len)
    {
        dst[i] = s2_len[i - s1_len];
        i += 1;
    }
    dst[i] = '\0';
    return (dst);
}

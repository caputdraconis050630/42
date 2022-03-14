void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char   *dest;

    dest = (unsigned char *)b;
    while (len > 0)
    {
        *dest = (unsigned char)c;
        dest += 1;
        len -= 1;
    }
    return (b);
}

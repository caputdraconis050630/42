void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char   *dstaddr;
    unsigned char   *srcaddr;
    int             i;

    dstaddr = (unsigned char *)dst;
    srcaddr = (unsigned char *)src;
    i = 0;
    while (i < len)
    {
        dstaddr[i] = srcaddr[i];
        i += 1;  
    }
    dstaddr[i] = '\0';
    return (dst);
}

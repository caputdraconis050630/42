int strncmp(const char *s1, const char *s2, size_t n)
{
    int index;

    index = 0;
    while (s1[index] && s2[index] && s1[index] == s2[index])
    {
        index += 1;
    }
    if (index == n)
        return (0);
    if (index != 0)
    {
        
    }
    return (s1[index] - s2[index]);
}

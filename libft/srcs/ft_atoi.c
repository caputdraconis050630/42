int ft_isspace(const char c)
{
    if (c >= 9 && c <= 13)
        return (1);
    if (c == 32)
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    unsigned int    num;
    int             sign;
    int             index;

    num = 0;
    sign = 1;
    index = 0;

    // Skip White Space
    while (str[index] && ft_isspace(str[index]) != 0)
        index += 1;
    
    // Process Sign
    if (str[index] == '+' || str[index] == '-')
    {
        if (str[index] == '-')
            sign *= -1;
        index += 1;
    }
    while (str[index] >= '0' && str[index] <= '9')
    {
        num = (num * 10) + (str[index] - '0');
        index += 1;
    }
    return (num * sign);
}

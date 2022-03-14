

void    ft_write_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
        write(fd, "-2147483648", 11);
    else
    {
        if (n < 0)
        {
            ft_write_fd('-', fd);
            n *= -1;
        }
        if (n > 9)
            ft_putnbr_fd(n / 10, fd);
        ft_write_fd(n % 10 + '0', fd);
    }
    return ;
}
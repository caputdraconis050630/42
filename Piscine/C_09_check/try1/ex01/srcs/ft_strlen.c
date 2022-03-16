

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += 1;
	return (len);
}

#include <unistd.h>

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len += 1;
	return (len);
}

int ft_strstr(char *str, char *to_find)
{
	int	i = 0;
	int	j;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
		{
			j += 1;
			if (j == ft_strlen(to_find))
				return (1);
		}
		i += 1;
	}
	return (0);
}

char *ft_strcatch(char *str, int len)
{
	// get a string of [len] length from given [str]

}

int main(int argc, char **argv)
{
	int start = 0;
	int length;

	if (argc <= 1)
		return (-1);
	while (argv[1][start])
	{
		len = 1;
		
	}
}

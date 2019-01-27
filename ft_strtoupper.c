// Header

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
}
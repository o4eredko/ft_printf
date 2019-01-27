// Header
void	ft_strrev(char *str, int len)
{
	char	c;
	int		i;

	i = -1;
	while (++i < --len)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
	}
}
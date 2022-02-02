int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || (c == 32))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (*str != '\0' && ft_isspace(*str))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str != '\0') && ('0' <= *str) && (*str <= '9'))
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	if (result > __LONG_MAX__ && sign == 1)
		return (-1);
	if (result > __LONG_MAX__ && sign == -1)
		return (0);
	return (result * sign);
}
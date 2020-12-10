int	g_buf[255];
char	*g_base;
int	g_len;

int	is_valid(char *c)
{
	if (*c == 0 || c[1] == 0)
		return (0);
	while (*c)
	{
		if ((*c >= 9 && *c <= 13) || *c == 32)
			return (0);
		else if (g_buf[(int)*c] == 1 || *c == '+' || *c == '-')
			return (0);
		else if (g_buf[(int)*c] == 0)
			g_buf[(int)*c] = 1;
		c++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int m_cnt;
	int ret;
	int i;

	m_cnt = 0;
	ret = 0;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m_cnt++;
		str++;
	}
	while (g_buf[(int)*str] == 1 && *str != 0)
	{
		while(g_base[i] != *str)
			i++;
		ret = ret * g_len + i;
		str++;
	}
	return (m_cnt % 2 ? -ret : ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int ret;
	
	g_len = 0;
	g_base = base;
	while(*base)
	{
		g_len++;
		base++;
	}
	ret = ft_atoi(str);
	return (ret);
}

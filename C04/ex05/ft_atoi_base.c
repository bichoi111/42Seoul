/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:11:55 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/06 16:11:58 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_buf[255];
int		g_len;
char	*g_base;

int		check_non_valid(char *c)
{
	int	i;

	i = 0;
	while (i < 255)
		g_buf[i++] = 0;
	if (*c == '\0' || c[1] == '\0')
		return (0);
	while (*c)
	{
		if ((*c >= 9 && *c <= 13) || *c == 32)
			return (0);
		else if (*c == '-' || *c == '+' || g_buf[(int)*c] == 1)
			return (0);
		else if (g_buf[(int)*c] == 0)
			g_buf[(int)*c] = 1;
		c++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int		minus_cnt;
	int		atoi_ret;
	int		i;

	minus_cnt = 0;
	atoi_ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_cnt++;
		str++;
	}
	while (g_buf[(int)*str] == 1 && *str != '\0')
	{
		i = 0;
		while (g_base[i] != *str)
			i++;
		atoi_ret = g_len * atoi_ret + i;
		str++;
	}
	return (minus_cnt % 2 ? -atoi_ret : atoi_ret);
}

int		ft_atoi_base(char *str, char *base)
{
	int		ret;

	g_len = 0;
	g_base = base;
	if (check_non_valid(base) == 0)
		return (0);
	while (*base)
	{
		g_len++;
		base++;
	}
	ret = ft_atoi(str);
	return (ret);
}

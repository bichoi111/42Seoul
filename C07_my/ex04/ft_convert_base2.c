/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:33:25 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/10 19:23:44 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				g_buf[255];
int				g_len;

int				is_valid(char *c)
{
	if (*c == '\0' || c[1] == '\0')
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

int				cnt_base_len(char *base)
{
	int			i;

	i = 0;
	while (i < 255)
		g_buf[i++] = 0;
	i = 0;
	while (base[i])
	{
		g_buf[(int)base[i++]] = 1;
	}
	return (i);
}

long long		ft_atoi_base(char *str, char *base)
{
	int			m_cnt;
	long long	ret;
	int			i;

	m_cnt = 0;
	ret = 0;
	g_len = cnt_base_len(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m_cnt++;
		str++;
	}
	while (g_buf[(int)*str] == 1 && *str != '\0')
	{
		i = 0;
		while (base[i] != *str)
			i++;
		ret = ret * g_len + i;
		str++;
	}
	return (m_cnt % 2 ? -ret : ret);
}

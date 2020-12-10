/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:51:18 by bichoi            #+#    #+#             */
/*   Updated: 2020/11/30 16:25:37 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_len;
int	g_result;
int	g_i;

int		my_pow(int i)
{
	int		pow_tmp;

	pow_tmp = 1;
	while (i-- > 0)
		pow_tmp *= 10;
	return (pow_tmp);
}

void	my_atoi(char *c)
{
	if (g_i == g_len)
		return ;
	else
	{
		g_result += (*c - '0') * my_pow(g_i);
		g_i++;
		my_atoi(--c);
	}
}

int		check_minus(char *str)
{
	int minus_cnt;

	minus_cnt = 0;
	while (*str)
	{
		if (*str == '-')
			minus_cnt++;
		str++;
	}
	return (minus_cnt % 2 ? -g_result : g_result);
}

int		ft_atoi(char *str)
{
	char	*tmp;

	tmp = str;
	g_i = 0;
	g_result = 0;
	while (*str)
	{
		g_len = 0;
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
			{
				str++;
				g_len++;
			}
			my_atoi(--str);
			return (check_minus(tmp));
		}
		else
			str++;
	}
	return (0);
}

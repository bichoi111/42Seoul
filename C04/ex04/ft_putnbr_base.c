/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:12:27 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/06 16:12:33 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				g_buf[255];
unsigned int	g_len;

void	buf_init(void)
{
	int		i;

	i = 0;
	while (i < 255)
		g_buf[i++] = 0;
}

int		check_non_valid(char *c)
{
	buf_init();
	if (*c == '\0' || c[1] == '\0')
		return (0);
	while (*c)
	{
		if (*c == '-' || *c == '+')
			return (0);
		if (g_buf[(int)*c] == 1)
			return (0);
		else if (g_buf[(int)*c] == 0)
			g_buf[(int)*c] = 1;
		c++;
	}
	return (1);
}

void	recur(unsigned int nb, char *base)
{
	if (nb / g_len == 0)
		write(1, &base[nb % g_len], 1);
	else
	{
		recur(nb / g_len, base);
		write(1, &base[nb % g_len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	*tmp;

	g_len = 0;
	tmp = base;
	if (check_non_valid(base) == 0)
		return ;
	else
	{
		while (*tmp)
		{
			tmp++;
			g_len++;
		}
		if (nbr < 0)
		{
			write(1, "-", 1);
			recur(-nbr, base);
		}
		else
			recur(nbr, base);
	}
}

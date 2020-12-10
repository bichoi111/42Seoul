/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:07:38 by bichoi            #+#    #+#             */
/*   Updated: 2020/11/27 03:35:49 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_zero_and_max(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		nb = 0;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	return (nb);
}

void	put_positive_num(int nb)
{
	int		p;
	int		r;
	char	c_r;

	while (nb)
	{
		p = nb / 10;
		r = nb % 10;
		if (p == 0)
		{
			c_r = r + '0';
			write(1, &c_r, 1);
			return ;
		}
		else
		{
			c_r = r + '0';
			put_positive_num(p);
			write(1, &c_r, 1);
		}
		nb = 0;
	}
}

void	ft_putnbr(int nb)
{
	nb = check_zero_and_max(nb);
	put_positive_num(nb);
}

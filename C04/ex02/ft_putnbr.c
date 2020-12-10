/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:05:02 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/06 16:06:58 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(int nb)
{
	char	r;

	if (nb == 0)
		return ;
	r = '0' + nb % 10;
	recur(nb / 10);
	write(1, &r, 1);
}

void	ft_putnbr(int nb)
{
	char	tmp;

	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		tmp = (-(nb % 10)) + '0';
		recur(-(nb / 10));
		write(1, &tmp, 1);
	}
	else
		recur(nb);
}

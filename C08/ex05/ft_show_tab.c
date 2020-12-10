/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:13:26 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/10 00:51:59 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_num(int nb)
{
	char	c;

	if (nb / 10)
		print_num(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		print_num(par->size);
		write(1, "\n", 1);
		write(1, par->copy, par->size);
		write(1, "\n", 1);
		par++;
	}
}

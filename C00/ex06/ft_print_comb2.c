/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:06:29 by bichoi            #+#    #+#             */
/*   Updated: 2020/11/28 19:51:23 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char i, char j, char k, char l)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, " ", 1);
	write(1, &k, 1);
	write(1, &l, 1);
	if (!(i == '9' && j == '8'))
		write(1, ", ", 2);
}

void	behind_num(char i, char j, char k, char l)
{
	while (k <= '9')
	{
		while (l <= '9')
		{
			print_num(i, j, k, l);
			l++;
		}
		k++;
		l = '0';
	}
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;
	char	k;
	char	l;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			k = i;
			l = j + 1;
			behind_num(i, j, k, l);
			j++;
		}
		i++;
	}
}

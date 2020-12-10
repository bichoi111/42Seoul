/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:29:35 by bichoi            #+#    #+#             */
/*   Updated: 2020/11/28 19:44:17 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_len;
char	g_buf[10];

void	next_num(char present_num, int idx)
{
	if (idx == g_len - 1)
	{
		write(1, g_buf, g_len);
		if (g_buf[0] != '0' + (10 - g_len))
			write(1, ", ", 2);
		return ;
	}
	while (present_num <= '0' + (10 - g_len + idx))
	{
		g_buf[idx + 1] = ++present_num;
		next_num(present_num, idx + 1);
	}
}

void	ft_print_combn(int n)
{
	g_len = n;
	g_buf[0] = '0';
	while (g_buf[0] <= '0' + (10 - g_len))
	{
		next_num(g_buf[0], 0);
		g_buf[0]++;
	}
}

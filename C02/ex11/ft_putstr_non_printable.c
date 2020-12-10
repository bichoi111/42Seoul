/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:25:10 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/02 05:18:07 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_hex[16] = "0123456789abcdef";
char	g_buf[2];

void	dec_to_hex(unsigned char c)
{
	g_buf[0] = g_hex[c / 16];
	g_buf[1] = g_hex[c % 16];
	write(1, "\\", 1);
	write(1, g_buf, 2);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (' ' <= *str && *str <= '~')
			write(1, str, 1);
		else
			dec_to_hex(*str);
		str++;
	}
}

int main()
{
	char a[] = "dff\x8egldp";
	ft_putstr_non_printable(a);
	return 0;
}

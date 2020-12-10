/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:11:38 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/10 19:44:03 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				is_valid(char *c);
long long		ft_atoi_base(char *str, char *base);
int				cnt_base_len(char *base);

long long		ret_size(long long nb, char *base)
{
	long long	base_len;
	int			cnt;

	base_len = cnt_base_len(base);
	cnt = 0;
	if (nb < 0)
	{
		cnt += 1;
		nb = -nb;
	}
	while (nb / base_len)
	{
		cnt++;
		nb = nb / base_len;
	}
	return (cnt + 1);
}

char			*ft_putnbr(long long nb, char *base)
{
	char		*ret;
	long long	size;
	long long	base_len;

	base_len = cnt_base_len(base);
	size = ret_size(nb, base);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
	}
	ret[size] = '\0';
	while (nb / base_len)
	{
		ret[--size] = base[nb % base_len];
		nb /= base_len;
	}
	ret[0] = base[nb % base_len];
	return (ret);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	atoi_ret;
	char		*ret;

	if (is_valid(base_from) == 0 || is_valid(base_to) == 0)
		return (0);
	atoi_ret = ft_atoi_base(nbr, base_from);
	ret = ft_putnbr(atoi_ret, base_to);
	return (ret);
}

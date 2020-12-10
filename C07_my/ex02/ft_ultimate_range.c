/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:47:48 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/08 17:50:32 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int len;
	int *buf;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len);
	buf = *range;
	if (!buf)
		return (-1);
	while (min < max)
	{
		*buf = min++;
		buf++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:58:11 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/07 18:36:16 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	i;
	int *ptr;

	i = 0;
	if (min >= max)
		return (0);
	ptr = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
		ptr[i++] = min++;
	return (ptr);
}

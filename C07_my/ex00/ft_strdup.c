/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:30:06 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/07 18:34:08 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	ptr = (char *)malloc(sizeof(char) * len);
	while (*src)
	{
		ptr[i++] = *src;
		src++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:02:34 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/08 00:04:42 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *c)
{
	int		i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_strcat(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2)
	{
		s1[i++] = *s2;
		s2++;
	}
	s1[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		idx;
	int		ret_len;

	idx = -1;
	ret_len = 0;
	if (size <= 0)
	{
		ret = (char *)malloc(1);
		ret[0] = 0;
		return (ret);
	}
	while (++idx < size)
		ret_len += ft_strlen(strs[idx]);
	ret_len += ft_strlen(sep) * (size - 1);
	idx = -1;
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	ret[0] = 0;
	while (++idx < size)
	{
		ft_strcat(ret, strs[idx]);
		if (idx + 1 < size)
			ft_strcat(ret, sep);
	}
	return (ret);
}

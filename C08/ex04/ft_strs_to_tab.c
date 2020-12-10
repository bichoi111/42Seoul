/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:56:48 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/10 00:56:00 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void				ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int			i;
	int			len;

	ptr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		ptr[i].size = len;
		ptr[i].str = (char *)malloc(sizeof(char) * (len + 1));
		ptr[i].copy = (char *)malloc(sizeof(char) * (len + 1));
		ft_strcpy(ptr[i].str, av[i]);
		ft_strcpy(ptr[i].copy, av[i]);
		i++;
	}
	ptr[i].str = 0;
	return (ptr);
}

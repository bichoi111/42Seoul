/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:05:52 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/06 18:05:53 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}

void	print_argv(int argc, char **argv)
{
	int j;

	j = 1;
	while (j < argc)
	{
		while (*argv[j])
		{
			write(1, argv[j], 1);
			argv[j]++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		cnt;
	char	*tmp;

	cnt = 1;
	while (cnt != 0)
	{
		i = 1;
		cnt = 0;
		while (i + 1 < argc)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) == 1)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				cnt++;
			}
			i++;
		}
	}
	print_argv(argc, argv);
	return (0);
}

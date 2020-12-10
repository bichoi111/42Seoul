/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:07:04 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/02 02:12:08 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		while (*argv[argc - i])
		{
			write(1, argv[argc - i], 1);
			argv[argc - i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

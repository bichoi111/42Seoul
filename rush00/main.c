/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoshin <hoshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:28:16 by hoshin            #+#    #+#             */
/*   Updated: 2020/11/22 17:57:07 by hoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush04.c"

int		main(int argc, char *argv[])
{
	int nargv1;
	int nargv2;

	nargv1 = atoi(argv[1]);
	nargv2 = atoi(argv[2]);
	rush(nargv1, nargv2);
	return (0);
}

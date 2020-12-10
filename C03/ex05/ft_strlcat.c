/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:03:30 by bichoi            #+#    #+#             */
/*   Updated: 2020/12/01 20:16:53 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int ret;

	ret = 0;
	while (*dest && ret < size)
	{
		dest++;
		ret++;
	}
	while (*src && ret + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		ret++;
	}
	if (ret < size)
		*dest = '\0';
	while (*src)
	{
		ret++;
		src++;
	}
	return (ret);
}

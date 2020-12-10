/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:49:32 by bichoi            #+#    #+#             */
/*   Updated: 2020/11/28 21:44:38 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *tmp1;
	char *tmp2;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			tmp1 = str;
			tmp2 = to_find;
			while (*tmp1 == *tmp2 && *tmp1 != '\0' && tmp2 != '\0')
			{
				tmp1++;
				tmp2++;
			}
			if (*tmp2 == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

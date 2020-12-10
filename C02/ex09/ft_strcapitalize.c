/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bichoi <bichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:55:38 by bichoi            #+#    #+#             */
/*   Updated: 2020/11/29 16:04:27 by bichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strlowcase(char *str)
{
	while (*str != ' ' && *str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		if (!((*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9')))
			return (str);
		str++;
	}
	return (str);
}

char	*start_num_check(char *str)
{
	if (*str >= '0' && *str <= '9')
		str = strlowcase(++str);
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp)
	{
		tmp = start_num_check(tmp);
		if (*tmp >= 'a' && *tmp <= 'z')
		{
			*tmp -= 32;
			tmp = strlowcase(++tmp);
		}
		else if (*tmp >= 'A' && *tmp <= 'Z')
		{
			tmp = strlowcase(++tmp);
		}
		if (*tmp == '\0')
			return (str);
		else
			tmp++;
	}
	return (str);
}

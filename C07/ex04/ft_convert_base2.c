#include <stdlib.h>
#include "ft_convert_base.c"

int is_valid(char *c);
int ft_atoi_base(char *str, char *base);
int g_len; // 다른 파일에 있는 변수가지고 오고 싶을때!

int get_nb_len(unsigned int nb)
{
	unsigned int len;

	len = 0;
	while (nb / 10)
	{
		len++;
		nb = (nb / 10);
	}
	return (len + 1);
}

char *ft_putnbr(unsigned int nb, char *base)
{
	char	*ptr;
	unsigned int	nb_len;

	nb_len = get_nb_len(nb);
	ptr = (char *)malloc(sizeof(char) * (nb_len + 1));
	ptr[nb_len] = 0; // 마지막 문자에 널문자
	while (nb / g_len)
	{
		ptr[--nb_len] = base[nb % g_len];
		nb = nb / g_len;
	}
	ptr[0] = base[nb % g_len];
	return (ptr);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int atoi_ret;
	char *ret;

	if (is_valid(base_from) == 0 || is_valid(base_to) == 0)
		return (0);
	atoi_ret = ft_atoi_base(nbr, base_from);
	if (atoi_ret < 0)
		ret = ft_putnbr(-atoi_ret, base_to);
	else
		ret = ft_putnbr(atoi_ret, base_to);
	return (ret);
}
#include <stdio.h>
int main()
{
	char *nbr = " ---1234d";
	char *base_from = "0123456789";
	char *base_to = "@!";
	printf("%s", ft_convert_base(nbr, base_from, base_to));
	return (0);
}

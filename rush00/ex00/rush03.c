#include <unistd.h>

int		minus_exception(int x, int y)
{
	if ((x < 0) || (y < 0))
	{
		ft_putchar('e');
		return (1);
	}
	else if ((x == 0) || (y == 0))
	{
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

void	display_shape(int x, int y, int i, int j)
{
	while (i <= y)
	{
		while (j <= x)
		{
			if (((i > 1) && (i < y)) && ((j > 1) && (j < x)))
				ft_putchar(' ');
			else if (((i == 1) && (j == 1)) || ((i == y) && (j == 1)))
				ft_putchar('A');
			else if (((i == 1) && (j == x)) || ((i == y) && (j == x)))
				ft_putchar('C');
			else
				ft_putchar('B');
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 1;
	}
}

int		rush(int x, int y)
{
	int mexception;

	mexception = minus_exception(x, y);
	if (mexception == 1)
	{
		return (0);
	}
	display_shape(x, y, 1, 1);
	return (0);
}

#include <libfillit.h>



int initialisation(int *dies, int *x, int *y, t_piece *piece)
{
	*dies = 0;
	*x = piece->x;
	*y = piece->y;
	return (0);
}

void initialisation2(int *x, int *y, t_piece *piece)
{
	*x = piece->x;
	*y = *y + 1;
}

int	verifsquare(char **square, t_piece *piece, int dies)
{
	int i;
	int len;
	int x;
	int y;

	len = ft_strlen(square[0]);
	i = initialisation(&len, &x, &y, piece);
	while (dies < 4)
	{
		if (i % 4 == 0 && i != 0 && y < len)
			initialisation2(&x, &y, piece);
		if (y >= len) 
			return (3);
		if (piece->piece[i] != '.')
		{
			if (x > len)
				return (2);
			if (square[y][x] != '.')
				return (1);			
			dies++;
		}
		i++;
		x++;
	}
	return (0);
}

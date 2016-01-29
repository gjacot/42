/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:55:15 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/29 16:58:16 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

int		checkerror(char *buf, int i, int line, int col)
{
	if (buf[i] != '#' && buf[i] != '.' && line != 4 && col != 4)
		return (0);
	else if ((line == 4 || col == 4) && buf[i] != '\n')
		return (0);
	return (1);
}

void	nextsquare(int *col, int *line, int *dies, int *i)
{
	*col = 0;
	*line = 0;
	*dies = 0;
	*i = *i + 1;
	if (*i % 21 != 0)
		error();
}

int		filecheck(char *buf, int i, int line)
{
	int dies;
	int col;

	dies = 0;
	col = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			dies++;
		if (checkerror(buf, i, line, col) != 1 || dies > 4)
			error();
		i++;
		line++;
		if (line > 4)
		{
			line = 0;
			col++;
		}
		if (col == 4 && buf[i] == '\n' && dies == 4)
			nextsquare(&col, &line, &dies, &i);
	}
	if (buf[i - 1] != '\n' || (buf[i - 2] != '.' && buf[i - 2] != '#'))
		error();
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		i;
	int		line;

	line = 0;
	i = 0;
	if (argc != 2)
		error2("usage: ./fillit source_file\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (filecheck(buf, i, line) == 1)
		lastcheck(buf, i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:55:15 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/07 17:27:00 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 4096

int	error(void)
{
	ft_putstr("error\n");
	return (0);
}

int	filecheck(char *buf, int i, int line)
{
	int col;
	int dies;

	dies = 0;
	col = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '#' && buf[i] != '.' && line != 4 && col != 4)
			return (error());
		else if ((line == 4 || col == 4) && buf[i] != '\n')
			return (error());
		else if (buf[i] == '#')
			dies++;
		if (dies > 4)
			return (error());
		i++;
		line++;
		if (line > 4)
		{
			line = 0;
			col++;
		}
		if (col > 4 && buf[i] == '\n')
		{
			col = 0;
			line = -1;
			dies = 0;
			i++;
		}
		printf("line: %d\ncol: %d\ndies: %d\nchar: %c\n", line, col, dies, buf[i]);
	}
	ft_putstr("ok\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		i;
	int		line;

	line = 0;
	i = 0;
	if (argc != 2)
		return (error());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error());
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	filecheck(buf, i, line);
	return (0);
}

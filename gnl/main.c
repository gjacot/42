/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:45:26 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/30 15:34:56 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		j;

	j = 3;
	line = NULL;
	if (argc == 2)
	{
			fd = open(argv[1], O_RDONLY);
			get_next_line(fd, &line);
			ft_putstr(line);
		return (0);
	}
	return (-1);
}

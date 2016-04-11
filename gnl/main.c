/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:45:26 by gjacot            #+#    #+#             */
/*   Updated: 2016/04/06 15:41:33 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		j;
	int		i;
	int		ret;

	j = 3;
	i = 1;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			ft_putstr("-------appel ");
			ft_putnbr(i);
			ft_putstr("-------\n");
			if (line != NULL)
			{
				ft_putstr("final line = ");
				ft_putstr(line);
			}
			else 
			  ft_putstr("line vide");
			if (line)
			ft_strdel(&line);
			i++;
			j--;
			ft_putchar('\n');
		}
		printf("derrnier appel:\n%s", line);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:41:27 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/22 15:30:31 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_next_line(char **line, int i, char *tmp)
{

}

int		get_next_line(const int fd, char **line)
{
	static int	i;
	int			ret;
	static char *tmp;

	if (!i > 0)
		i = 0;
	ret = 0;
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	ret = read(fd, *line, BUFF_SIZE);
	*line[ret] = '\0';
	while (*line[i] != '\n' && *line[i] != '\0')
	{
		ft_putchar(*line[i]);
		i++;
	}
	if (*line[i] == '\n')
		get_next_next_line(line, i, tmp);
	else
		get_next_line(fd, line);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:41:27 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/31 18:26:37 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_next_line(int *i, char *tmp)
{
	while (tmp[*i] != '\n' && tmp[*i] != '\0')
			i++;
	if (tmp[*i] == '\n')
	{
		while (tmp[*i] != '\0')
		{

		}
	}
	return (0);
}

void	lastcheck(char **line)
{
	int len;

	ft_putstr("ok\n");
	len = ft_strlen(*line);
	ft_putnbr(len);
	ft_putchar('\n');
	ft_putchar(*line[len - 1]);
	ft_putchar('\n');
	if (*line[len] == '\n')
	{
		*line[len] = '\0';
		ft_putstr("ok\n");
	}
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	static char	*tmp;

	ret = 0;
	i = 0;
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	tmp = ft_strnew(BUFF_SIZE);
	*line = NULL;
	while (ft_strchr(tmp, '\n') == NULL)
	{
		i = 0;
		ret = read(fd, tmp, BUFF_SIZE);
		tmp[ret] = '\0';
		get_next_next_line(&i, tmp);
		if (*line != NULL)
			*line = ft_strjoin(*line, tmp);
		else
			*line = ft_strsub(tmp, 0, *i);
	}
	lastcheck(line);
	return (0);
}

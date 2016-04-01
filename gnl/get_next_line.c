/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:41:27 by gjacot            #+#    #+#             */
/*   Updated: 2016/04/01 17:59:32 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_next_line(char *tmp)
{
	int i;
	int len;

	len = ft_strlen(tmp);
	i = 0;
	while (tmp[i] != '\n' && i < len)
		i++;
	return (i);
}

void	lastcheck(char **line)
{
	int		len;
	char	*n;
	int		i;

	i = 0;
	n = ft_strchr(*line, '\n');
	len = ft_strlen(*line);
	if (n != NULL)
	{
		n = ft_strsub(*line, 0, len);
		free(*line);
		while (n[i] != '\n')
			i++;
		*line = ft_strsub(n, 0, i);
	}
}

void	save_tmp(char *tmp)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(tmp);
	while (tmp[i - 1] != '\n')
		i++;
	tmp = ft_strsub(tmp, i, len);
}

void	tmp_check(char **tmp, char **line)
{
	*tmp = ft_strnew(BUFF_SIZE);
	*line = NULL;
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
	if (tmp == NULL)
		tmp_check(&tmp, line);
	else
		*line = ft_strsub(tmp, 0, ft_strlen(tmp));
	while (ft_strchr(tmp, '\n') == NULL || ft_strcmp(tmp, *line) == 0)
	{
		i = 0;
		ret = read(fd, tmp, BUFF_SIZE);
		i = get_next_next_line(tmp);
		if (*line != NULL)
			*line = ft_strjoin(*line, tmp);
		else
			*line = ft_strsub(tmp, 0, i);
	}
	save_tmp(tmp);
	lastcheck(line);
	return (0);
}

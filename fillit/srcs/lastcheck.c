/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:23:04 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/14 21:49:26 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <stdio.h>

int	isnextto(int *die, int j, int *line)
{
	if (die[j] - 1 == die[j - 1] || die[j] - 5 == die[j - 1])
		*line = *line + 1;
	if (die[j] - 1 == die[j - 2] || die[j] - 5 == die[j - 2])
		*line = *line + 1;
	if (die[j] - 1 == die[j - 3] || die[j] - 5 == die[j - 3])
		*line = *line + 1;
	if (die[j] + 1 == die[j + 1] || die[j] + 5 == die[j + 1])
		*line = *line + 1;
	if (die[j] + 1 == die[j + 2] || die[j] + 5 == die[j + 2])
		*line = *line + 1;
	if (die[j] + 1 == die[j + 3] || die[j] + 5 == die[j + 3])
		*line = *line + 1;
	return (0);
}

int	countline(int *die)
{
	int j;
	int line;

	j = 0;
	line = 0;
	while (j < 4)
	{
		isnextto(die, j, &line);
		j++;
	}
	return (line);
}

int	lastcheck(char *buf, int i)
{
	int j;
	int die[4];
	int fi;

	j = 0;
	i = 0;
	fi = i;
	while (buf[i] != '\0')
	{
		while (j < 4)
		{
			while (buf[i] != '#')
				i++;
			die[j] = i;
			i++;
			j++;
		}
		printf("countline = %d\n", countline(die));
		if (!(countline(die) == 8 || countline(die) == 6))
			error();
		i = fi + 21;
		j = 0;
		fi = i;
	}
	solveit(buf);
	return (1);
}

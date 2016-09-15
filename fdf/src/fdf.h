/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:15:42 by gjacot            #+#    #+#             */
/*   Updated: 2016/09/15 15:59:06 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/libft.h"


typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*first;
	struct s_point	*prev;
	struct s_point	*next;
}					t_point;

typedef struct		s_mlx
{
	void			*mlx;
	void			*img;
	int				x;
	int				y;
	int				color;
	int				bit;
	int				end;
	int				*data;
	void			*win;
}					t_mlx;

typedef struct		s_env
{
	char	*getline;
	t_point *point;
	t_mlx	*mlx;
	int		line;
	t_point	**lines;
	int		line_i;
	int		fd;
	int		y_max;
}					t_env;

t_point				*fill_lst(int nb, t_env *e);

#endif

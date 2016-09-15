/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:15:42 by gjacot            #+#    #+#             */
/*   Updated: 2016/08/18 17:23:22 by gjacot           ###   ########.fr       */
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
	int				i;
	int				x;
	int				y;
	int				z;
	struct s_point	*prev;
	struct s_point	*next;
}					t_point;

typedef struct		s_line
{
	int				y;
	struct s_point	*first;
	struct s_line	*up;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_img
{
	struct s_point	*first;
	void			*mlx;
	void			*img;
	int				x;
	int				y;
	int				ymax;
	int				color;
	int				bit;
	int				line;
	int				end;
	int				*data;
	void			*win;
}					t_img;

int					mlx_pixel_put_image(t_img *img);
int					ft_beguin_draw(t_img *img, t_line *line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:22:16 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/27 16:02:37 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILLIT_H
# define LIBFILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUF_SIZE 4096

typedef	struct		s_piece
{
	char			*piece;
	struct s_piece	*next;
	int				x;
	int				y;
	char			lettre;
	struct s_piece	*prev;
}					t_piece;

int					error(void);
int					error2(char *str);
void				affiche_lst(t_piece *lst);
void				clearsquare(char **piece, int taille);
int					isnextto(int *die, int j, int *line);
int					countline(int *die);
int					lastcheck(char *buf, int i);
int					checkerror(char *buf, int i, int line, int col);
void				nextsquare(int *col, int *line, int *dies, int *i);
int					filecheck(char *buf, int i, int line);
void				moveit(t_piece piece, int taille, char *tab, char **square);
t_piece				*newpiece(char lettre);
int					verif_collone(char *tab, int num);
int					verif_ligne(char *tab, int num);
void				update_ligne(char *tab, char lettre);
void				update_collone(char *tab, char lettre);
void				posi(char *tab, int lettre);
t_piece				*remplir_list(char **tab_piece, t_piece *lst);
int					firstsquare(int i);
void				affiche(char **tab_piece);
int					solveit(char *buf);
int					compte_tab(char *buf);
void				**remplir_tab(char *buf, char **tab_piece);
char				**inittab(char *buf);
char				**initsquare(int square);
int					verifsquare(char **square, int taille,
					char *tab, int coord[1]);

#endif

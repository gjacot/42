/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:22:16 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/20 17:24:50 by jgiraude         ###   ########.fr       */
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
	char			**piece;
	struct s_piece	*next;
	int				x;
  	int				y;
	char			lettre;
	struct s_piece	*prev;
}					t_piece;

int		error(void);
int		error2(char *str);
int		test(void);
int		lastcheck(char *buf, int i);
int		solveit(char *buf);
char	**inittab(char *buf);
void	**remplir_tab(char *buf, char **tab_piece);
void	affiche(char **tab_piece);
int		compte_tab(char *buf);
char	**initsquare(int square);
int		verif_collone(char *tab, int num);
int		verif_ligne(char *tab, int num);
void	update_ligne(char *tab, int var);
void	update_collone(char *tab, int var);
void	posi(char *tab);


#endif






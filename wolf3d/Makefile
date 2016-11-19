#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 15:33:41 by gjacot            #+#    #+#              #
#    Updated: 2016/11/19 17:20:00 by gjacot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
FUNC = main.c ft_wolf.c ft_wall.c ft_move.c ft_draw.c ft_event.c ft_map.c
SRCS = $(addprefix ./src/, $(FUNC))
OBJ = $(SRCS:.c=.o)
CC = clang
FLAGS = -Wall -Werror -Wextra
all: lib $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ -lmlx -framework OpenGL -framework AppKit libft/libft.a
%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<
lib:
	make -C libft/
clean: lclean
	@echo "Suppression fichier obj"
	@rm -rf $(OBJ)
	@echo "Suppression terminée"
lclean:
	make -C libft/ clean
fclean: clean lfclean
	@echo "Suppression executable wolf3d"
	@rm -f $(NAME)
	@echo "Suppression terminée"
lfclean:
	make -C libft/ fclean
afclean: fclean lfclean
re: fclean all
rego: re go

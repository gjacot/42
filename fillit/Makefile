# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:30:30 by jgiraude          #+#    #+#              #
#    Updated: 2016/03/14 14:31:16 by jgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit
SRC_NAME =	./mainfillit.c \
		./error.c	\
		./lastcheck.c	\
		./solveit.c	\
		./tab.c	\
		./newpiece.c \
		./posi.c \
		./versquaregui.c \
		./remplir_list.c \
		./moveitjojo.c \
		./clearsquare.c \
		./verifpiece.c \

CC 			= gcc

CPPFLAGS 	= -I$(INC_PATH)

CFLAGS 		= -Werror -Wall -Wextra $(CPPFLAGS)
CFLAGS_D 	= $(CFLAGS) -g $(CPPFLAGS)

LIBFT 		= -Llibft/ -lft
SRC_PATH 	= ./srcs/
OBJ_PATH 	= ./objs/
INC_PATH 	= ./incs/

OBJ_NAME = $(SRC_NAME:.c=.o)


SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@mkdir -p $(OBJ_PATH)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ)
	@echo "$(NAME) » Création du binaire en mode RELEASE..."


debug: debug2
	@mkdir -p $(OBJ_PATH)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@$(CC) $(CFLAGS_D) $(LIBFT) -o $(NAME) $(OBJ)
	@echo "$(NAME) » Création du binaire en mode DEBUG..."

$(OBJ_NAME): $(SRC)
	@make all -C libft/ > /dev/null
	@$(CC) $(CFLAGS) $(LIBF) -c $(SRC)
	@echo "$(NAME) » Création des fichiers objets en mode RELEASE."

debug2:
	@make all -C libft/ > /dev/null
	@$(CC) $(CFLAGS_D) $(LIBF) -c $(SRC)
	@echo "$(NAME) » Création des fichiers objets en mode DEBUG."


clean:
	@rm -fv $(OBJ) > /dev/null
	@rm -Rf $(OBJ_PATH) > /dev/null || true
	@make clean -C libft/ > /dev/null

fclean: clean
	@rm -fv $(NAME) > /dev/null
	@rm -fv libft/libft.a > /dev/null

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h
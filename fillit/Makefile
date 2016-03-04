#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 12:55:13 by gjacot            #+#    #+#              #
#    Updated: 2016/03/02 17:11:11 by gjacot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	./mainfillit.c \
		./error.c	\
		./lastcheck.c	\
		./solveit.c	\
		./tab.c	\
		./newpiece.c \
		./posi.c \
		./verifsquargui.c \
		./affiche_lst.c \
		./remplir_list.c \
 		./moveitulti.c \
 		./clearsquare.c \
 		./verifpiece.c \

HEAD = -I ./include

LIB = -L ./include -lft

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -g $(HEAD) -o $(NAME) $(SRC) $(LIB)

clean:
		rm -f *.c~
fclean: clean
		rm -f $(NAME)
re: fclean all
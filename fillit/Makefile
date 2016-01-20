#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 12:55:13 by gjacot            #+#    #+#              #
#    Updated: 2016/01/20 16:12:08 by gjacot           ###   ########.fr        #
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
		./verifsquare.c \

HEAD = -I ./include

LIB = -L ./include -lft

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror $(HEAD) -o $(NAME) $(SRC) $(LIB)

clean:
		rm -f *.c~
fclean: clean
		rm -f $(NAME)
re: fclean all
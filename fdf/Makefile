#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/06 18:15:52 by gjacot            #+#    #+#              #
#    Updated: 2016/08/30 16:36:07 by gjacot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf
INC_LIB		=	-L./libft/ -lft
DIRSRC      =   ./src/
DIROBJ		=	./obj/
SRC			= 	./main.c \
				./fdf.c	\

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	 -Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e


$(NAME)	:		$(OBJ)
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE))
endif
				$(CC) $(INCLUDE) $(INC_LIB) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  -o $(NAME) $(OBJS)
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
ifdef SUB_MAKE
				@($(MAKE) clean)
endif
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE
				@($(MAKE) fclean)
endif
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

%.o		:		$(DIRSRC)/%.c
				$(CC) $(INCLUDE) $(CFLAGS) -o $(DIROBJ)/$@ -c $<

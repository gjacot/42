# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 19:13:54 by jgiraude          #+#    #+#              #
#    Updated: 2016/01/09 16:05:28 by jgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ./

INC_NAME = libft.h

SRC_NAME = ft_atoi.c\
		   ft_white.c\
		   ft_puthello.c\
		   ft_addition.c\
		   ft_soustraction.c\
		   ft_division.c\
		   ft_lstadd.c\
		   ft_lstdel.c\
		   ft_lstdelone.c\
		   ft_lstiter.c\
		   ft_lstmap.c\
		   ft_lstnew.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_NAME))

all : $(NAME)

$(NAME) :
	gcc -c $(SRC_NAME)
	ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)

clean: 
	rm -fv $(OBJ_NAME)

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC_NAME)
	norminette $(INC_PATH)*.h

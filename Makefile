# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/28 18:31:22 by mzane             #+#    #+#              #
#    Updated: 2015/05/23 14:30:39 by mzane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
SRC = main.c  env.c exec_bin.c utils.c buffer.c error.c ft_cd.c signal.c \
	  setenv.c unsetenv.c path.c
LIB_H = -I libft/
LIB = libft/libft.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -g -o $(NAME) $(OBJ) $(LIB_H) $(LIB)

$(OBJ): $(SRC)
	make -C libft/
	gcc -Wall -Wextra -Werror -g -c $(LIB_H) $(SRC)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

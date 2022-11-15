# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 09:53:27 by bvarlamo          #+#    #+#              #
#    Updated: 2022/11/15 17:06:24 by bvarlamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= con

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

SRC = main.cpp 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 14:41:27 by mbousset          #+#    #+#              #
#    Updated: 2025/12/04 15:04:03 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ := c++

C++_FLAGS := -Wall -Werror -Wextra -std=c++98

SRC := main.cpp

OBJ := $(SRC:.cpp=.o)

NAME := Exec

all:$(NAME)

$(NAME):$(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

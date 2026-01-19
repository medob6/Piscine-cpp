# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 08:32:00 by mbousset          #+#    #+#              #
#    Updated: 2025/10/06 13:40:02 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ := c++

C++_FLAGS := -Wall -Werror -Wextra -std=c++98 #-g3 -fsanitize=address

SRC := main.cpp randomChump.cpp newZombie.cpp Zombie.cpp

OBJ := $(SRC:.cpp=.o)

NAME := Zombie

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

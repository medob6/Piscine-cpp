# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 14:08:19 by mbousset          #+#    #+#              #
#    Updated: 2025/10/06 18:22:39 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ := c++

C++_FLAGS := -Wall -Werror -Wextra -std=c++98

SRC := Account.cpp tests.cpp\

OBJ := $(SRC:.cpp=.o)
	
NAME := CrappySoftware


all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 17:43:14 by mbousset          #+#    #+#              #
#    Updated: 2025/10/06 17:43:24 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


C++_FLAGS := c++ -Wall -Werror -Wextra -std=c++98

SRC := main.cpp 

OBJ := $(SRC:.cpp=.o)

NAME = fight

all:$(NAME)

$(NAME):$(OBJ)
	$(C++_FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean re all
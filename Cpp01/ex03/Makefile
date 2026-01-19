# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 16:13:51 by mbousset          #+#    #+#              #
#    Updated: 2025/10/06 17:40:07 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++_FLAGS := c++ -Wall -Werror -Wextra -std=c++98

SRC := main.cpp  Weapon.cpp  HumanA.cpp  HumanB.cpp

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
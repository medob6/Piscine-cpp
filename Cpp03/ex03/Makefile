# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 18:20:28 by mbousset          #+#    #+#              #
#    Updated: 2025/10/18 12:09:25 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++_FLAGS := c++ -Wall -Werror -Wextra -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Exec

all:$(NAME)

$(NAME):$(OBJ)
	$(C++_FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
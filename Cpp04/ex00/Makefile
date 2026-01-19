# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 11:57:00 by mbousset          #+#    #+#              #
#    Updated: 2025/10/22 14:22:42 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++_FLAGS = c++ -Werror -Wall -Wextra -std=c++98

SRC := Animal.cpp  Cat.cpp  Dog.cpp  main.cpp  WrongAnimal.cpp  WrongCat.cpp

OBJ = $(SRC:.cpp=.o)
NAME = Exec

all:$(NAME)

$(NAME):$(OBJ)
	$(C++_FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:clean fclean all re
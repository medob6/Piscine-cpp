# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 16:50:54 by mbousset          #+#    #+#              #
#    Updated: 2025/12/28 16:22:48 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

C++_FLAGS = -Wall -Wextra -Werror -std=c++98  -Ofast  #-fsanitize=address -g3

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

NAME = PmergeMe

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

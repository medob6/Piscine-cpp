# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 16:50:54 by mbousset          #+#    #+#              #
#    Updated: 2025/12/18 16:57:53 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

C++_FLAGS = -Wall -Wextra -Werror -std=c++98  #-O0 -g3-fsanitize=address

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

NAME = btc

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

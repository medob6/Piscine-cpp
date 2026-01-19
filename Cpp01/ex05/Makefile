# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 16:13:57 by mbousset          #+#    #+#              #
#    Updated: 2025/10/08 16:24:54 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++_FLAGS := c++ -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Harl

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 08:26:38 by mbousset          #+#    #+#              #
#    Updated: 2025/12/02 09:33:13 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

C++_FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Base.cpp

OBJ = $(SRC:.cpp=.o)

NAME = check_type

all: $(NAME)

$(NAME):$(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
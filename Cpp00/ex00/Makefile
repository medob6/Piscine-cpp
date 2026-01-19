# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 17:44:21 by mbousset          #+#    #+#              #
#    Updated: 2025/09/30 17:22:18 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = 	megaphone.cpp

OBJ = $(SRC:.cpp=.o)

NAME = megaphone

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
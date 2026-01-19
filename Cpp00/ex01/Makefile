# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 10:18:40 by mbousset          #+#    #+#              #
#    Updated: 2025/10/15 14:36:08 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
C++_FLAGS =-g3 -Wall -Wextra -Werror -std=c++98

SRC = 	phonebook.cpp helperfunc.cpp

OBJ = $(SRC:.cpp=.o)

NAME = CrappySoftware

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
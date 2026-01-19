# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 08:26:38 by mbousset          #+#    #+#              #
#    Updated: 2025/12/03 09:41:30 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

C++_FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = CharLiteral.cpp  DoubleLiteral.cpp  FloatLiteral.cpp  IntLiteral.cpp  Literal.cpp  main.cpp  ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

NAME = scalar_converter

all: $(NAME)

$(NAME):$(OBJ)
	@$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	@$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
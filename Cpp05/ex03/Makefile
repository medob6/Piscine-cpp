# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 13:14:58 by mbousset          #+#    #+#              #
#    Updated: 2025/11/28 09:14:16 by mbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++_FLAGS = c++ -Werror -Wall -Wextra -std=c++98

SRC := main.cpp  Bureaucrat.cpp AForm.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp  PresidentialPardonForm.cpp Intern.cpp

OBJ = $(SRC:.cpp=.o)
NAME = Exec

all:$(NAME)

$(NAME):$(OBJ)
	@$(C++_FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	@$(C++_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:fclean all

.PHONY:clean fclean all re
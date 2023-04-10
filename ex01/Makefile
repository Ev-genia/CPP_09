# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 11:58:10 by mlarra            #+#    #+#              #
#    Updated: 2023/04/04 22:27:39 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	RPN

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

CC		=	c++

.PHONY: 	all clean fclean re

SRC		=	main.cpp RPN.cpp

HEADER	=	RPN.hpp

OBJ		=	${SRC:.cpp=.o}

RM		=	rm -f

all:		${NAME}

${NAME}:	${HEADER} ${OBJ}
	${CC} ${FLAGS} ${SRC} -o ${NAME}

%.o:	%.cpp ${HEADER}
	${CC} ${FLAGS} -c $< -o $@
clean:
	${RM} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:		fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 20:20:05 by mlarra            #+#    #+#              #
#    Updated: 2023/04/04 22:27:45 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btc

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

CC		=	c++

RM		=	rm -f

.PHONY: 	all clean fclean re

SRC		=	main.cpp BitcoinExchange.cpp

HEADER	=	BitcoinExchange.hpp

OBJ		=	${SRC:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
	${CC} ${FLAGS} ${SRC} -o ${NAME}

%.o:	%.cpp ${HEADER}
	${CC} ${FLAGS} -c $< -o $@
clean:
	${RM} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:		fclean all
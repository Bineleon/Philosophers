# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:32:17 by bineleon          #+#    #+#              #
#    Updated: 2024/12/28 19:03:59 by bineleon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			= \033[0;32m\e[1m
RESET			= \e[0m\033[0m

NAME						= philo
SRC_MAIN				= main.c
SRC							= utils.c utils_2.c init_struct.c
CC							= cc
RM							= rm -f
FLAGS						= -Wall -Wextra -Werror -g3 -pthread
OBJ_DIR					= obj/
SRC_DIR					= ./

OBJ 						= ${addprefix ${OBJ_DIR},${SRC:.c=.o}}
MAIN_OBJ        = ${addprefix ${OBJ_DIR},${SRC_MAIN:.c=.o}}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@${CC} ${FLAGS} -c $< -o $@

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${MAIN_OBJ} ${OBJ}
	@${CC} ${FLAGS} ${MAIN_OBJ} ${OBJ} -o ${NAME}
	@echo "${GREEN}Philo       : DONE!${RESET}"

all: ${NAME}

clean:
	@${RM} -rf $(OBJ_DIR) ${NAME}
	@echo "${GREEN}Clean       : DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@echo "${GREEN}Full clean  : DONE!${RESET}"

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:57:46 by aloubar           #+#    #+#              #
#    Updated: 2021/09/14 20:06:07 by aloubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS				=		./srcs/push_swap.c \
						./srcs/memory_managment.c \
						./srcs/radix_sorting.c \
						./srcs/rules_managment.c \
						./srcs/sort_low_numbers.c \
						./srcs/split_args.c \
						./srcs/utils.c \

INCLUDES		=		./libft/libft.h \
						./includes/push_swap.h \

HEAD			= 		./includes/

LIBFT			=		./libft/libft.a

LIB_DIR			=		./libft/

NAME			=		push_swap

CC				=		clang

OBJS			=		${SRCS:.c=.o}

RM				=		rm -f

CFLAGS			=		-Wall -Werror -Wextra

.c.o:
						@${CC} ${CFLAGS} -I${HEAD} -c $< -o ${<:.c=.o}
						@echo "${GREEN}[  OK  ]${ORANGE} ${<:.s=.o} ${NC}"

all:					${NAME}

${NAME}:				${OBJS}
						@make -C ${LIB_DIR}
						@echo "${GREEN}\n[  OK  ] libft has been successfully created.${NC}"
						@${CC} ${CFLAGS} -I${HEAD} -o ${NAME} ${OBJS} ${LIBFT}
						@echo "${GREEN}[  OK  ] push_swap has been successfully created.\n${NC}"
clean:
			@make -C $(LIB_DIR) clean
			@${RM} ${OBJS}
			@echo "${GREEN}\n[  OK  ]${RED} *.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[  OK  ]${RED} libft has been sucessfully deleted.${NC}"
			@${RM} ${NAME}
			@echo "${GREEN}[  OK  ]${RED} push_swap has been successfully deleted.\n${NC}"
			
re:					fclean all

.PHONY:				all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:41:24 by tgernez           #+#    #+#              #
#    Updated: 2023/02/22 13:03:46 by tgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
FTSRCS			= .c
DIRSRCS 		= srcs/programme/
SRCS 			=	$(addsuffix ${FTSRCS},	\
					$(addprefix ${DIRSRCS},	\
					main	\
					utils	\
					phases	\
					find_case	\
					parsing_1	\
					parsing_2	\
					atoi_def	\
					best_choice	\
					converting	\
					instructions_1	\
					instructions_2	\
					nodes_functions \
					do_instructions	\
					sorting_functions	\
					instructions_optimizer	\
					instruction_functions	\
					))
DIRBONUS		= srcs/bonus/
BONUS			=	$(addsuffix ${FTSRCS},	\
					$(addprefix ${DIRBONUS},	\
					main	\
					parsing_1	\
					parsing_2	\
					converting	\
					execution	\
					init		\
					instructions_1	\
					instructions_2	\
					memory_cleaning	\
					))	\
					srcs/programme/atoi_def.c
BONUSOBJS		= ${BONUS:.c=.o}
INCLUDES		= -Iincludes
LIBFTDIR		= libft
LIBFTLIB		= -lft
CC				= cc
FLAGS			= -Wall -Wextra -Werror
OBJS			= ${SRCS:.c=.o}
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ ${INCLUDES}

all: ${NAME}
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${NAME}: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} ${INCLUDES} -L${LIBFTDIR} ${LIBFTLIB} -o $@ -g3

sanitize: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} ${INCLUDES} -L${LIBFTDIR} ${LIBFTLIB} -o push_swap -g3 -fsanitize=address

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

bonus: ${BONUSOBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${BONUSOBJS} ${INCLUDES} -L${LIBFTDIR} ${LIBFTLIB} -o checker -g3

safe:
	git add .
	git commit -m "SEMIAUTO-SAFEGUARD"
	git push

#----------------------------PUSH_SWAP

clean:
	@echo "${CYAN}Cleaned ${NAME}${NC}"
	@${RM} ${OBJS}
fclean:		clean
	@echo "${CYAN}FCleaned ${NAME}${NC}"
	@${RM} ${NAME}

re: fclean all

bonus_clean:
	@${RM} ${BONUSOBJS}

bonus_fclean: bonus_clean
	@${RM} checker

bonus_re: bonus_fclean bonus

#----------------------------LIBFT

libft_all:
	@make -C ${LIBFTDIR} all

libft_clean:
	@make -C ${LIBFTDIR} clean

libft_fclean:
	@make -C ${LIBFTDIR} fclean


libft_re:
	@make -C ${LIBFTDIR} re

#----------------------------ALL

all_clean: clean libft_clean bonus_clean

all_fclean: fclean libft_fclean bonus_fclean

all_re: libft_re bonus_re re
	@echo "${CYAN}Re-ed ${NAME}${NC}"


.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean all_clean all_fclean bonus bonus_clean bonus_fclean bonus_re

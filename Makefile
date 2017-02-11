# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:45:43 by ntoniolo          #+#    #+#              #
#    Updated: 2017/02/11 13:38:54 by ntoniolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ntoniolo.filler

DIR_LFT = libft/

DIR_MLXJI = libmlxji

FLAGS = -Wall -Werror -Wextra

SRC_FILLER = srcs/main.c \
			 srcs/dastrat/data_forme.c \
			 srcs/dastrat/data_place.c \
			 srcs/dastrat/strat_aggro.c \
			 srcs/dastrat/strat_envelop.c \
			 srcs/dastrat/strat_expend_x.c \
			 srcs/dastrat/strat_expend_y.c \
			 srcs/draw_filler/draw_case.c \
			 srcs/draw_filler/draw_extern.c \
			 srcs/draw_filler/draw_grid.c \
			 srcs/draw_filler/draw_heart.c \
			 srcs/draw_filler/draw_piece.c \
			 srcs/draw_filler/draw_solve.c \
			 srcs/heart_filler/run_dastrat.c \
			 srcs/heart_filler/can_place.c \
			 srcs/heart_filler/diff_map.c \
			 srcs/heart_filler/free.c \
			 srcs/heart_filler/ft_lstinsert.c \
			 srcs/heart_filler/loop_filler.c \
			 srcs/heart_filler/solution.c \
			 srcs/heart_filler/char_players.c \
			 srcs/heart_filler/key_event.c \
			 srcs/parsing/pars.c \
			 srcs/parsing/limit_piece.c 

CC = gcc

OBJET_FILLER = $(SRC_FILLER:.c=.o)

.PHONY: all, clean, fclean, , re, $(NAME), lmlxji, lft, start, end

all: lmlxji start $(NAME) end

$(NAME): $(OBJET_FILLER)
	@$(CC) $(FLAGS) $(OBJET_FILLER) -L./libft/ -lft -L./libmlxji/ -lmlxji -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@cp $(NAME) ./ressources/players/

start:
	@echo "\033[4m\033[33mCreation de $(NAME)   ...\033[0m"

end:
	@echo "\033[4m\033[1m\033[32m>$(NAME) done.\033[0m"

srcs/%.o: srcs/%.c
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@gcc $(FLAGS) -c $^ -o $@

lmlxji:
	@(cd $(DIR_MLXJI) && $(MAKE))
	@(cd $(DIR_LFT) && $(MAKE))

clean:
	@echo "\033[31mDelete .o of $(NAME)\033[0m"
	@/bin/rm -f $(OBJET_FILLER)
	@(cd $(DIR_LFT) && make clean)
	@(cd $(DIR_MLXJI) && make clean)

fclean: clean
	@echo "\033[31mDelete .o and ressources/players/$(NAME)\033[0m"
	@/bin/rm -f ressources/players/$(NAME)
	@/bin/rm -f $(NAME)
	@(cd $(DIR_LFT) && make fclean)
	@(cd $(DIR_MLXJI) && make fclean)

re: fclean all

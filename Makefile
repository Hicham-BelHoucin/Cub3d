# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:08:41 by hbel-hou          #+#    #+#              #
#    Updated: 2022/08/17 14:47:32 by hbel-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

BONUS = Cub3d_bonus

CC = cc 

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

INCLUDE = includes/Cub3d.h includes/Cub3d_bonus.h libft/libft.h

SRC =   game/cast_rays.c \
		game/create_window.c \
		game/draw_ceilling_and_floor.c \
		game/handle_keys.c \
		game/init.c \
		game/main.c \
		game/ternary.c \
		game/tools.c \
		game/movement.c \
		game/draw_wall.c \
		parsing/checkElements.c \
		parsing/checkMap.c \
		parsing/error.c \
		parsing/getMap.c \
		parsing/getNextLine.c \
		parsing/utils.c \

BNSSRC = bonus/cast_rays.c     \
		bonus/main.c     \
		bonus/movement_bonus.c	 \
		bonus/tools.c	 \
		bonus/_tools.c	 \
		bonus/__tools.c	 \
		bonus/rendering_walls.c	 \
		bonus/key_handlers.c	 \
		mandatory/parsing/checkElements.c \
		mandatory/parsing/checkMap.c \
		mandatory/parsing/error.c \
		mandatory/parsing/getMap.c \
		mandatory/parsing/getNextLine.c \
		mandatory/parsing/utils.c \
		mandatory/game/ternary.c \
		mandatory/game/cast_rays.c \
		mandatory/game/tools.c \
		mandatory/game/movement.c \
		mandatory/game/draw_wall.c \
		mandatory/game/draw_ceilling_and_floor.c \
		mandatory/game/handle_keys.c \
		mandatory/game/init.c \

SRCS = $(addprefix mandatory/, $(SRC))

SRCOBJ = $(SRCS:.c=.o)

BONUSOBJ = $(BNSSRC:.c=.o)

all : $(NAME)

$(NAME): $(SRCOBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft
	@echo "\033[0;32m"
	@echo "░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░"
	@echo "██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗"
	@echo "██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║"
	@echo "██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║"
	@echo "╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝"
	@echo "░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░"
	@echo "\033[0m"
	@$(CC) $(SRCS) libft/libft.a  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BONUSOBJ) $(SRCOBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft
	@echo "\033[0;32m"
	@echo "░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░ ██████╗░░█████╗░███╗░░██╗██╗░░░██╗░██████╗"
	@echo "██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗ ██╔══██╗██╔══██╗████╗░██║██║░░░██║██╔════╝"
	@echo "██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║ ██████╦╝██║░░██║██╔██╗██║██║░░░██║╚█████╗░"
	@echo "██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║ ██╔══██╗██║░░██║██║╚████║██║░░░██║░╚═══██╗"
	@echo "╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝ ██████╦╝╚█████╔╝██║░╚███║╚██████╔╝██████╔╝"
	@echo "░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░ ╚═════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═════╝░"
	@echo "\033[0m"
	@$(CC) $(BNSSRC) libft/libft.a  -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@  -c $<

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(SRCOBJ) $(BONUSOBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME) $(BONUS)
re : fclean all
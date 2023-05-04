# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 18:02:10 by jhesso            #+#    #+#              #
#    Updated: 2023/05/04 16:08:04 by jhesso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CFLAGS			=	-Wall -Wextra -Werror
MLX				=	-lmlx -framework OpenGL -framework AppKit
LIBFT			=	libft.a
LIBFT_DIR		=	libft/
SRC_PATH		=	src/
OBJ_PATH		=	obj/
SRC				=	main.c\
					read_map.c map_validation.c flood_fill.c map_coordinates.c\
					utils.c debug.c error.c\
					game.c window.c mlx_init.c draw_map.c\
					event.c move.c
SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJ				=	$(SRC:.c=.o)
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
INCS			=	-I includes/

# pretty colors for the messages
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
RESET			=	\033[0m

all: libft $(OBJ_PATH) $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@cc $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJS) libft
	@echo "$(BLUE)Compiling $(NAME)$(RESET)"
	@cc $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)done$(RESET)"

linux: $(OBJS) libft
	cc $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

debug:
	cc $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -g

clean:
	@echo "$(RED)removing object files$(RESET)"
	@/bin/rm $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)cleaning all compiled stuff.. :)$(RESET)"
	@/bin/rm $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@/bin/rm -rf $(OBJ_PATH)
	@echo "$(RED)done$(RESET)"

re: fclean all

.PHONY: all libft clean fclean linux re

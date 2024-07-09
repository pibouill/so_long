# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 13:22:42 by pibouill          #+#    #+#              #
#    Updated: 2024/07/09 19:16:02 by pibouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long
CC			:=	cc
RM			:=	rm -rf
CFLAGS		:=	-Wall -Werror -Wextra -g
MLX_FLAGS	:=
LINUX_FLAGS :=	-ldl -lglfw -pthread -lm
MACOS_FLAGS :=	-lglfw -framework Cocoa -framework OpenGL -framework IOKit
SRC_DIR		:=	src
INC_DIR		:=	-I ./inc/
MLX_DIR		:=	lib/MLX42/
MLX_INC		:=	-I ./lib/MLX42/include/MLX42
MLX_A		:= ./lib/MLX42/build/libmlx42.a
LIB_DIR		:=	lib
LIBFT_DIR	:=	libft
LIBFT_INC	:=	-I ./libft/inc/
BIN_DIR		:=	bin
LIBFT_CUT	:= $(shell echo $(LIBFT_DIR) | cut -c 4-)

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_FLAGS += $(LINUX_FLAGS)
endif
ifeq ($(UNAME), Darwin)
	MLX_FLAGS += $(MACOS_FLAGS)
endif


################################################################################
## COLORS

ifeq ($(UNAME), Linux)
	RED			:= \e[38;5;196m
	ORANGE		:= \e[38;5;208m
	GREEN		:= \033[0;92m
	YELLOW      := \033[0;93m
	BLUE        := \033[0;94m
	END_COLOR	:= \033[0;39m
endif
ifeq ($(UNAME), Darwin)
	GREEN		:= \033[0;92m
	YELLOW      := \033[0;93m
	BLUE        := \033[0;94m
	RED         := \033[0;91m
	END_COLOR   := \033[0m
endif

################################################################################
## SOURCES

SRC_FILES	:=	main\
				args_check\
				free_utils\
				map_check\
				utils\
				get_map_info\
				build_map_array\
				error_utils\
				map_path_check\
				img_to_map\
				moves\
				hooks\
				update_player

SRC			:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ			:= $(addprefix $(BIN_DIR)/, $(addsuffix .o, $(SRC_FILES)))

################################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	+@make -C libft --no-print-directory
	+@$(CC) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -l $(LIBFT_CUT) $(MLX_A) $(MLX_INC) $(MLX_FLAGS)
	+@echo "$(GREEN)[ $(NAME) compiled. ]$(END_COLOR)"

mlx: 
	+@if [ ! -d $(MLX_DIR) ]; then \
        git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
		cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4; \
		printf "$(GREEN)\n------------------------\n\n$(END_COLOR)"; \
		printf "$(GREEN)MLX42 built.\n$(END_COLOR)"; \
		printf "$(GREEN)\n------------------------\n$(END_COLOR)"; \
		echo "$(ORANGE)\nYou can now make.$(END_COLOR)"; \
	else \
		printf "$(GREEN)\n------------------------\n\n$(END_COLOR)"; \
		printf "$(GREEN)MLX42 already built.\n$(END_COLOR)"; \
		printf "$(GREEN)\n------------------------\n$(END_COLOR)"; \
    fi

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile libft/src/*.c | $(BIN_DIR)
	+@$(CC) -c $(CFLAGS) $(INC_DIR) $(LIBFT_INC) $(MLX_INC) $< -o $@
	+@echo "$(BLUE)Compiling... $(notdir $<)$(END_COLOR)"

$(BIN_DIR):
	+@mkdir $(BIN_DIR)
	+@echo "$(YELLOW)Created $(BIN_DIR)/ directory at $(NAME)/$(END_COLOR)"

clean:
	 +@rm -rf $(BIN_DIR)
	 +@echo "$(GREEN)$(NAME) object files cleaned.$(END_COLOR)"
	 +@make clean -C libft --no-print-directory

fclean: clean
	+@$(RM) bin $(NAME) libft/libft.a
	+@echo "$(YELLOW)$(NAME) executable file cleaned.$(END_COLOR)"
	+@echo "$(YELLOW)lib/MLX42 cleaned.$(END_COLOR)"
	+@printf "$(ORANGE)$(NAME) bin/ cleaned\n$(END_COLOR)"

re: fclean all
	+@echo "$(RED)Cleaned all and rebuilt $(NAME) and $(LIBFT_DIR)$(END_COLOR)"

################################################################################
## PHONY

.PHONY: all clean fclean re mlx

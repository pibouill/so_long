# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:56:08 by pibouill          #+#    #+#              #
#    Updated: 2024/05/31 12:45:37 by pibouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM 				= rm -rf
AR 				= ar rc
SRC_DIR			= src
INC_DIR			= inc
BIN_DIR			= bin

# **************************************************************************** #
# COLORS

GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
END_COLOR		= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES		=		ft_atoi\
						ft_atoi_base\
						ft_atol\
						ft_bzero\
						ft_calloc\
						ft_digitcount\
						ft_intlen\
						ft_isalnum\
						ft_isalpha\
						ft_isascii\
						ft_isdigit\
						ft_isprint\
						ft_itoa\
						ft_lstadd_back\
						ft_lstadd_front\
						ft_lstclear\
						ft_lstdelone\
						ft_lstiter\
						ft_lstlast\
						ft_lstmap\
						ft_lstnew\
						ft_lstsize\
						ft_memchr\
						ft_memcmp\
						ft_memcpy\
						ft_memmove\
						ft_memset\
						ft_print_bits\
						ft_printf\
						ft_putchar\
						ft_putchar_fd\
						ft_putendl_fd\
						ft_putnbr\
						ft_putnbr_fd\
						ft_putstr\
						ft_putstr_fd\
						ft_split\
						ft_str_arr_len\
						ft_strchr\
						ft_strdup\
						ft_striteri\
						ft_strjoin\
						ft_strlcat\
						ft_strlcpy\
						ft_strlen\
						ft_strmapi\
						ft_strncmp\
						ft_strnstr\
						ft_strrchr\
						ft_strtrim\
						ft_substr\
						ft_tolower\
						ft_toupper\
						get_next_line\
						putfcts_len\
						ft_wordcount\
						ft_printf_fd\
						putfcts_len_fd

SRC					= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ 				= $(addprefix $(BIN_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME): $(OBJ)
	+@$(AR) $(NAME) $(OBJ)
	+@echo "$(GREEN)$(NAME) compiled. $(END_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(BIN_DIR)
	+@$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@

$(BIN_DIR):
	+@mkdir $(BIN_DIR)
	+@echo "$(YELLOW)Created $(BIN_DIR)/ directory at libft/$(END_COLOR)"

clean:
	+@$(RM) $(BIN_DIR)
	+@echo "$(BLUE)$(NAME) bin/ cleaned.$(END_COLOR)"

fclean: clean
	+@$(RM) $(NAME)
	+@echo "$(YELLOW)$(NAME).a cleaned.$(END_COLOR)"

re: fclean all
	+@echo "$(GREEN)Cleaned all and rebuilt $(NAME)$(END_COLOR)"

# **************************************************************************** #

.PHONY: all clean fclean re

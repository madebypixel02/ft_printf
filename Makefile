# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 09:03:14 by aperez-b          #+#    #+#              #
#    Updated: 2021/11/30 14:50:23 by aperez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

UNAME = $(shell uname -s)
ECHO = echo
ifeq ($(UNAME), Linux)
	ECHO = echo -e
endif
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD
AR = ar rcs
SRC_DIR = src
INC_DIR = inc
SRCB_DIR = srcb
OBJ_DIR = obj
OBJB_DIR = objb
BIN_DIR = bin
BIN = libftprintf.a
NAME = $(BIN_DIR)/$(BIN)
LIBFT = libft/bin/libft.a


SRC = ft_printf.c			\
		ft_format.c			\
		ft_parse.c			\
		ft_print_chars.c		\
		ft_print_nbrs.c		\
		ft_print_hex.c

SRCB = ft_printf_bonus.c			\
		ft_format_bonus.c			\
		ft_parse_bonus.c			\
		ft_print_chars_bonus.c		\
		ft_print_nbrs_bonus.c		\
		ft_print_hex_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

all: $(NAME)

$(NAME): create_dirs compile_libft $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(ECHO) "$(GREEN)$(BIN) is up to date!$(DEFAULT)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) "Compiling $(BLUE)$<$(DEFAULT)..."
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs compile_libft $(OBJB)
	@$(AR) $(NAME) $(OBJB)
	@$(ECHO) "$(MAGENTA)Bonus Functions Compilation Complete in ft_printf!$(DEFAULT)"

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(ECHO) "Compiling $(BLUE)$<$(DEFAULT)..."
	@$(CC) $(CFLAGS) -c $< -o $@

compile_libft:
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/madebypixel02/libft.git; \
	fi
	@make all -C libft
	@cp $(LIBFT) $(NAME)

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJB_DIR)
	@mkdir -p $(BIN_DIR)

test: all
	@$(ECHO) "$(YELLOW)Performing test with custom main...$(DEFAULT)"
	@$(CC) -c tests/main.c
	@$(CC) main.o $(NAME)
	@./a.out $(UNAME) | cat -e
	@$(RM) main.o a.out
	@$(ECHO) "$(GREEN)Test Complete!$(DEFAULT)"

clean:
	@$(ECHO) "$(CYAN)Cleaning up object files in ft_printf...$(DEFAULT)"
	@if [ -d "libft" ]; then \
		make clean -C libft; \
	fi
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@if [ -d "libft" ]; then \
		$(RM) $(LIBFT); \
	fi
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"
	@if [ -d "libft" ]; then \
		$(ECHO) "$(CYAN)Removed $(LIBFT)$(DEFAULT)"; \
	fi

norminette:
	@$(ECHO) "$(CYAN)\nChecking norm for ft_printf...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(SRCB_DIR) $(INC_DIR)
	@if [ -d "libft" ]; then \
		make norminette -C libft/; \
	fi

git:
	git add .
	git commit
	git push

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d

.PHONY: all clean fclean bonus re norminette compile_libft create_dirs test git

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 09:03:14 by aperez-b          #+#    #+#              #
#    Updated: 2021/12/15 19:44:21 by aperez-b         ###   ########.fr        #
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

SHELL=/bin/bash

# Make variables
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
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
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

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))

all: $(NAME)

$(NAME): create_dirs compile_libft $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs compile_libft $(OBJB)
	@$(AR) $(NAME) $(OBJB)

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

compile_libft:
	@if [ ! -d "libft" ]; then \
		git clone https://gitlab.com/madebypixel02/libft.git; \
	fi
	@make all -C libft
	@cp $(LIBFT) $(NAME)

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJB_DIR)
	@mkdir -p $(BIN_DIR)

test: all
	@$(PRINTF) "\n$(YELLOW)Performing test with custom main...$(DEFAULT)\n\n"
	@$(CC) -c tests/main.c
	@$(CC) main.o $(NAME)
	@./a.out $(UNAME) | cat -e
	@$(RM) main.o a.out
	@$(PRINTF) "$(GREEN)Test Complete!$(DEFAULT)\n"

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in ft_printf...$(DEFAULT)\n"
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
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		$(PRINTF) "$(CYAN)Removed $(LIBFT)$(DEFAULT)\n"; \
	fi

norminette:
	@$(PRINTF) "$(CYAN)\nChecking norm for ft_printf...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(SRCB_DIR) $(INC_DIR)
	@if [ -d "libft" ]; then \
		make norminette -C libft/; \
	fi

git:
	git add .
	git commit
	git push

re: fclean
	@make all

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d

.PHONY: all clean fclean bonus re norminette compile_libft create_dirs test git

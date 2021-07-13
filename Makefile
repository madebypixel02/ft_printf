# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 09:03:14 by aperez-b          #+#    #+#              #
#    Updated: 2021/07/09 09:27:41 by aperez-b         ###   ########.fr        #
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
CC = gcc
AR = ar rcs
LIBFT = libft.a
NAME = libftprintf.a

SRC_M = mandatory/ft_printf.c				\
		mandatory/ft_format.c			\
		mandatory/ft_parse.c			\
		mandatory/ft_print_chars.c		\
		mandatory/ft_print_nbrs.c		\
		mandatory/ft_print_hex.c

SRC_B = bonus/ft_printf_bonus.c				\
		bonus/ft_format_bonus.c			\
		bonus/ft_parse_bonus.c			\
		bonus/ft_print_chars_bonus.c		\
		bonus/ft_print_nbrs_bonus.c		\
		bonus/ft_print_hex_bonus.c

OBJ_M = lib/ft_printf.o				\
		lib/ft_format.o			\
		lib/ft_parse.o			\
		lib/ft_print_chars.o		\
		lib/ft_print_nbrs.o		\
		lib/ft_print_hex.o

OBJ_B = lib/ft_printf_bonus.o			\
		lib/ft_format_bonus.o		\
		lib/ft_parse_bonus.o		\
		lib/ft_print_chars_bonus.o	\
		lib/ft_print_nbrs_bonus.o	\
		lib/ft_print_hex_bonus.o

all: $(NAME)
	@$(ECHO) "$(GREEN)$(NAME) Compilation Complete!$(DEFAULT)"

$(NAME): $(OBJ_M) $(LIBFT)
	@$(AR) $(NAME) $(OBJ_M)

$(OBJ_M): $(SRC_M)
	@$(ECHO) "$(RED)Mandatory objects outdated in ft_printf! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $(SRC_M)
	@mv -f ft_format.o ft_parse.o ft_print_chars.o ft_print_hex.o ft_print_nbrs.o ft_printf.o lib/

bonus: $(OBJ_B) $(LIBFT)
	@$(AR) $(NAME) $(OBJ_B)
	@$(ECHO) "$(MAGENTA)Bonuses Compilation Complete in ft_printf!$(DEFAULT)"

$(OBJ_B): $(SRC_B)
	@$(ECHO) "$(RED)Bonus objects outdated in ft_printf! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $(SRC_B)
	@mv -f ft_format_bonus.o ft_parse_bonus.o ft_print_chars_bonus.o ft_print_hex_bonus.o ft_print_nbrs_bonus.o ft_printf_bonus.o lib/

$(LIBFT):
	@make all -C libft
	@cp libft/$(LIBFT) $(NAME)

test: all
	@$(ECHO) "$(YELLOW)Performing test with custom main...$(DEFAULT)"
	@$(CC) -c tests/main.c
	@$(CC) main.o $(NAME)
	./a.out $(UNAME) | cat -e
	@$(RM) main.o a.out
	@$(ECHO) "$(GREEN)Test Complete!$(DEFAULT)"

test2: all
	@$(ECHO) "$(YELLOW)Performing test with custom main...$(DEFAULT)"
	@$(CC) -c tests/main2.c
	@$(CC) main2.o $(NAME)
	./a.out | cat -e
	@$(RM) main2.o a.out
	@$(ECHO) "$(GREEN)Test Complete!$(DEFAULT)"

clean:
	@$(ECHO) "$(BLUE)Cleaning up object files in ft_printf...$(DEFAULT)"
	@make clean -C libft
	@$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) libft/$(LIBFT)
	@$(RM) $(NAME)
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"
	@$(ECHO) "$(CYAN)Removed $(LIBFT)$(DEFAULT)"

norminette:
	@$(ECHO) "$(CYAN)Checking norm for ft_printf...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_M) $(SRC_B) lib/ft_printf.h
	@make norminette -C libft/

git:
	git add ../.
	git commit
	git push

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"

.PHONY: all clean fclean bonus re git

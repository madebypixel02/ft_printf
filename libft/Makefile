# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 10:28:33 by aperez-b          #+#    #+#              #
#    Updated: 2021/07/09 09:28:39 by aperez-b         ###   ########.fr        #
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
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = libft.h

SRC_M =	mandatory/ft_atoi.c mandatory/ft_bzero.c		\
	mandatory/ft_calloc.c mandatory/ft_nbrlen.c		\
	mandatory/ft_isspace.c mandatory/ft_itoa.c		\
	mandatory/ft_uitoa.c mandatory/ft_memccpy.c		\
	mandatory/ft_memchr.c mandatory/ft_memcmp.c		\
	mandatory/ft_memcpy.c mandatory/ft_isalnum.c		\
	mandatory/ft_isalpha.c mandatory/ft_isascii.c		\
	mandatory/ft_isdigit.c mandatory/ft_isprint.c		\
	mandatory/ft_memmove.c mandatory/ft_memset.c		\
	mandatory/ft_split.c mandatory/ft_strchr.c		\
	mandatory/ft_strdup.c mandatory/ft_strjoin.c		\
	mandatory/ft_strlcat.c mandatory/ft_strlcpy.c		\
	mandatory/ft_strlen.c mandatory/ft_strmapi.c		\
	mandatory/ft_strncmp.c mandatory/ft_strnstr.c		\
	mandatory/ft_strrchr.c mandatory/ft_strtrim.c		\
	mandatory/ft_substr.c mandatory/ft_tolower.c		\
	mandatory/ft_toupper.c mandatory/ft_putchar_fd.c	\
	mandatory/ft_putnchar_fd.c mandatory/ft_putendl_fd.c	\
	mandatory/ft_putnbr_fd.c mandatory/ft_putstr_fd.c	\
	mandatory/ft_putstrn_fd.c mandatory/ft_max.c

SRC_B = bonus/ft_lstadd_back.c	\
	bonus/ft_lstadd_front.c	\
	bonus/ft_lstclear.c	\
	bonus/ft_lstdelone.c	\
	bonus/ft_lstiter.c	\
	bonus/ft_lstlast.c	\
	bonus/ft_lstsize.c	\
	bonus/ft_lstnew.c	\
	bonus/ft_lstmap.c

OBJ_M =	lib/ft_atoi.o lib/ft_bzero.o			\
	lib/ft_calloc.o lib/ft_nbrlen.o			\
	lib/ft_isspace.o lib/ft_itoa.o			\
	lib/ft_uitoa.o lib/ft_memccpy.o			\
	lib/ft_memchr.o lib/ft_memcmp.o			\
	lib/ft_memcpy.o lib/ft_isalnum.o		\
	lib/ft_isalpha.o lib/ft_isascii.o		\
	lib/ft_isdigit.o lib/ft_isprint.o		\
	lib/ft_memmove.o lib/ft_memset.o		\
	lib/ft_split.o lib/ft_strchr.o			\
	lib/ft_strdup.o lib/ft_strjoin.o		\
	lib/ft_strlcat.o lib/ft_strlcpy.o		\
	lib/ft_strlen.o lib/ft_strmapi.o		\
	lib/ft_strncmp.o lib/ft_strnstr.o		\
	lib/ft_strrchr.o lib/ft_strtrim.o		\
	lib/ft_substr.o lib/ft_tolower.o		\
	lib/ft_toupper.o lib/ft_putchar_fd.o		\
	lib/ft_putnchar_fd.o lib/ft_putendl_fd.o	\
	lib/ft_putnbr_fd.o lib/ft_putstr_fd.o		\
	lib/ft_putstrn_fd.o lib/ft_max.o

OBJ_B = lib/ft_lstadd_back.o	\
	lib/ft_lstadd_front.o	\
	lib/ft_lstclear.o	\
	lib/ft_lstdelone.o	\
	lib/ft_lstiter.o	\
	lib/ft_lstlast.o	\
	lib/ft_lstsize.o	\
	lib/ft_lstnew.o		\
	lib/ft_lstmap.o

all: $(NAME)
	@$(ECHO) "$(GREEN)$(NAME) Compilation Complete!$(DEFAULT)"

$(NAME) : $(OBJ_M)
	@$(AR) $(NAME) $(OBJ_M)

$(OBJ_M): $(SRC_M)
	@$(ECHO) "$(RED)Mandatory objects outdated in libft! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $(SRC_M)
	@mv -f ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o				\
		ft_isdigit.o ft_isprint.o ft_isspace.o ft_itoa.o ft_max.o ft_memccpy.o ft_memchr.o		\
		ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_nbrlen.o ft_putchar_fd.o			\
		ft_putendl_fd.o ft_putnbr_fd.o ft_putnchar_fd.o ft_putstr_fd.o ft_putstrn_fd.o ft_split.o	\
		ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o		\
		ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o	\
		ft_uitoa.o lib/

bonus: $(OBJ_M) $(OBJ_B)
	@$(AR) $(NAME) $(OBJ_M) $(OBJ_B)
	@$(ECHO) "$(MAGENTA)Bonuses Compilation Complete in libft!$(DEFAULT)"

$(OBJ_B): $(SRC_B)
	@$(ECHO) "$(RED)Bonus objects outdated in libft! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $(SRC_M) $(SRC_B)
	@mv -f ft_lstadd_front.o ft_lstadd_back.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o		\
	ft_lstlast.o ft_lstsize.o ft_lstnew.o ft_lstmap.o lib/

clean:
	@$(ECHO) "$(BLUE)Cleaning up object files in libft...$(DEFAULT)"
	@$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"

norminette:
	@$(ECHO) "$(CYAN)Checking norm for libft...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_M) $(SRC_B) lib/libft.h

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"

.PHONY: all bonus clean fclean re 

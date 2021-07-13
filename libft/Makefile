# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 10:28:33 by aperez-b          #+#    #+#              #
#    Updated: 2021/07/13 14:24:48 by aperez-b         ###   ########.fr        #
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
DIR_M = mandatory
DIR_B = bonus
DIR_OBJ = lib

SOURCE_M =	ft_atoi.c ft_bzero.c		\
	ft_calloc.c ft_nbrlen.c		\
	ft_isspace.c ft_itoa.c		\
	ft_uitoa.c ft_memccpy.c		\
	ft_memchr.c ft_memcmp.c		\
	ft_memcpy.c ft_isalnum.c		\
	ft_isalpha.c ft_isascii.c		\
	ft_isdigit.c ft_isprint.c		\
	ft_memmove.c ft_memset.c		\
	ft_split.c ft_strchr.c		\
	ft_strdup.c ft_strjoin.c		\
	ft_strlcat.c ft_strlcpy.c		\
	ft_strlen.c ft_strmapi.c		\
	ft_strncmp.c ft_strnstr.c		\
	ft_strrchr.c ft_strtrim.c		\
	ft_substr.c ft_tolower.c		\
	ft_toupper.c ft_putchar_fd.c	\
	ft_putnchar_fd.c ft_putendl_fd.c	\
	ft_putnbr_fd.c ft_putstr_fd.c	\
	ft_putstrn_fd.c ft_max.c

SOURCE_B = ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c	\
	ft_lstdelone.c	\
	ft_lstiter.c	\
	ft_lstlast.c	\
	ft_lstsize.c	\
	ft_lstnew.c	\
	ft_lstmap.c

SRC_M = $(addprefix $(DIR_M)/, $(SOURCE_M))

OBJ_M =	$(addprefix $(DIR_OBJ)/, $(SOURCE_M:.c=.o))

SRC_B = $(addprefix $(DIR_B)/, $(SOURCE_B))

OBJ_B = $(addprefix $(DIR_OBJ)/, $(SOURCE_B:.c=.o))

all: $(NAME)
	@$(ECHO) "$(GREEN)$(NAME) Compilation Complete!$(DEFAULT)"

$(NAME) : $(OBJ_M)
	@$(AR) $(NAME) $(OBJ_M)

$(OBJ_M): $(SRC_M)
	@$(ECHO) "\n$(RED)Mandatory objects outdated in libft! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $(SRC_M)
	@mv -f $(SOURCE_M:.c=.o) $(DIR_OBJ)

bonus: $(OBJ_M) $(OBJ_B)
	@$(AR) $(NAME) $(OBJ_M) $(OBJ_B)
	@$(ECHO) "$(MAGENTA)Bonuses Compilation Complete in libft!$(DEFAULT)"

$(OBJ_B): $(SRC_B)
	@$(ECHO) "$(RED)Bonus objects outdated in libft! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $(SRC_B)
	@mv -f $(SOURCE_B:.c=.o) $(DIR_OBJ)

clean:
	@$(ECHO) "$(BLUE)Cleaning up object files in libft...$(DEFAULT)"
	@$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"

norminette:
	@$(ECHO) "$(CYAN)\nChecking norm for libft...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_M) $(SRC_B) lib/libft.h

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"

.PHONY: all bonus clean fclean re 

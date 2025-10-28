# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 13:24:06 by danfern3          #+#    #+#              #
#    Updated: 2025/10/28 14:52:31 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[0;32m
RESET	= \033[0m
GREY	= \033[1;30m
LWHITE	= \033[2;37m
LGREEN	= \033[2;32m

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS += -fsanitize=address
# CFLAGS += -lm
# CFLAGS += --no-print-directory

RM = rm -rf

INCLUDES = -I ./inc/headers -I $(LIBFT_DIR)

LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

# Sources
SRCS_DIR = ./src/solong/
SRCS = \
	file.c \
	game.c \
	map.c \
	so_long.c
SOURCES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# GNL sources
GNL_DIR = ./src/get_next_line/
GNL_SRCS = \
	get_next_line.c \
	get_next_line_utils.c

GNL_APPEND = $(addprefix $(GNL_DIR), $(GNL_SRCS))
SOURCES += $(GNL_APPEND)
OBJS += $(addprefix $(OBJ_DIR), $(GNL_SRCS:.c=.o))

# Objects
OBJ_DIR = ./src/obj/

# Input files
FILE = ./files/test.ber

# RULES
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o:$(GNL_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	: $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)"
	@echo "${GREY}Compilation ${GREEN}[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@echo "${GREY}Compiling libft ${GREEN}[OK]$(RESET)"

all: clearscreen obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "${LWHITE}Cleaning $(NAME)... ${LGREEN}✓$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

clearscreen:
	clear

run: all
	./$(NAME) $(FILE)

valgrind: all
	valgrind ./$(NAME) $(FILE)

debug: all
	clear
	gdb ./$(NAME)

.PHONY: all obj clean fclean re clearscreen run
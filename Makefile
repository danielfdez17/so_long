# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 13:24:06 by danfern3          #+#    #+#              #
#    Updated: 2025/11/17 08:18:37 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	= \033[0;32m
RESET	= \033[0m
GREY	= \033[1;31m
LWHITE	= \033[2;37m
LGREEN	= \033[2;32m

NO_PRINT = --no-print-directory

# Program name
NAME = so_long

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CFLAGS += -fsanitize=address

# Removal
RM = rm -rf

# Includes
INCLUDES = -I ./inc/headers -I $(LIBFT_DIR)

# LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

# Sources
SRCS_DIR = ./src/solong/
# SRCS = $(shell ls $(SRCS_DIR) -R | grep -E ".+\.c")
SRCS =	error.c \
		file.c \
		free.c \
		init.c \
		map.c \
		render.c \
		render_game.c \
		render_utils.c \
		so_long.c \
		validation.c \
		validation_utils.c
SOURCES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# ? GNL sources
GNL_DIR = ./src/get_next_line/
GNL_SRCS = \
	get_next_line.c \
	get_next_line_utils.c

GNL_APPEND = $(addprefix $(GNL_DIR), $(GNL_SRCS))
SOURCES += $(GNL_APPEND)
OBJS += $(addprefix $(OBJ_DIR), $(GNL_SRCS:.c=.o))

# ? MLX42
LIBMLX = ./inc/MLX42
INCLUDES += -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# MLX42 = ./inc/MLX42/libmlx42.a

# Objects
OBJ_DIR = ./src/obj/

# ? Input files
FILE = ./files/test.ber

# ? RULES
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o:$(GNL_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	: $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)"
	@echo "${GREY}Compilation ${GREEN}[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus $(NO_PRINT)
	@echo "${GREY}Compiling libft ${GREEN}[OK]$(RESET)"

all: libmlx obj $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean $(NO_PRINT)
	@$(RM) $(LIBMLX)/build
	@echo "${LWHITE}Cleaning $(NAME)... ${LGREEN}✓$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean $(NO_PRINT)

re: fclean all

# ! Automating / Debugging rules
run1: all
	clear
	./$(NAME) ./files/test.ber
run2: all
	clear
	./$(NAME) ./files/test2.ber

tests: all
	clear
	./$(NAME) ./files/bad_border.ber
	./$(NAME) ./files/bad_char.ber
	./$(NAME) ./files/bad_collectable_number.ber
	./$(NAME) ./files/bad_exit_number.ber
	./$(NAME) ./files/bad_extension.berro
	./$(NAME) ./files/bad_line_number.ber
	./$(NAME) ./files/bad_player_number.ber
	./$(NAME) ./files/no_exit1.ber
	./$(NAME) ./files/no_exit2.ber

# valgrind: all
# 	valgrind ./$(NAME) $(FILE)

# debug: all
# 	clear
# 	gdb ./$(NAME)

.PHONY: all libmlx obj clean fclean re run1 run2 tests

# Indicates the main rule to be executed
.GOAL: all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 13:24:06 by danfern3          #+#    #+#              #
#    Updated: 2025/10/26 13:41:34 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CCW = cc -Wall -Wextra -Werror

RM = rm -rf

SRCS = so_long.c \

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CCW) -c $< -o $@

$(NAME)	: $(OBJS)

clean:
	$(RM) $(OBJ_DIR)/

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
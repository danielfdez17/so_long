# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 07:42:17 by danfern3          #+#    #+#              #
#    Updated: 2025/10/27 10:05:44 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft.a

# Source files
SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

# Bonus source files
BONUS_SRCS = ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstsize_bonus.c

# Include files
INCS = libft.h

# Object files
# OBJS = $(SRCS:.c=.o)
OBJS = ft_atoi.o\
		ft_bzero.o\
		ft_calloc.o\
		ft_isalnum.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_itoa.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memmove.o\
		ft_memset.o\
		ft_putchar_fd.o\
		ft_putendl_fd.o\
		ft_putnbr_fd.o\
		ft_putstr_fd.o\
		ft_split.o\
		ft_strchr.o\
		ft_strdup.o\
		ft_striteri.o\
		ft_strjoin.o\
		ft_strlcat.o\
		ft_strlcpy.o\
		ft_strlen.o\
		ft_strmapi.o\
		ft_strncmp.o\
		ft_strnstr.o\
		ft_strrchr.o\
		ft_strtrim.o\
		ft_substr.o\
		ft_tolower.o\
		ft_toupper.o

# Bonus object files
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJS = ft_lstadd_back_bonus.o\
		ft_lstadd_front_bonus.o\
		ft_lstclear_bonus.o\
		ft_lstdelone_bonus.o\
		ft_lstiter_bonus.o\
		ft_lstlast_bonus.o\
		ft_lstmap_bonus.o\
		ft_lstnew_bonus.o\
		ft_lstsize_bonus.o

# Compiler and flags
CCW = cc -Wall -Wextra -Werror

# Memory flags for leaks detection
# SANITIZE = -fsanitize=address -g

# Removal
RM = rm -f

# Archiver
AR = ar -rcs

# Links a .c (and .h if needed) to its .o file
%.o: %.c
	@$(CCW) -c $< -o $@ -I INCS

# Compiles the whole program/library
all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@$(AR) $(NAME) $(OBJS)

# Compiles the bonus exercises
bonus: all $(BONUS_OBJS) $(INCS)
	@$(AR) $(NAME) $(BONUS_OBJS)

# Removes the object files
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

# Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)

# Rebuilds the program/library
re: fclean all

# Rebuilds the bonus program/library
rebonus: fclean bonus

# Executes norminette for every file
# norminette:
# 	echo Executing norminette for every file
# 	$(NORMINETTE) $(NCFLAGS) $(NHFLAGS) $(SRCS) $(HEADERS) $(BONUS_SRCS)

# .PHONY: all clean fclean re rebonus bonus

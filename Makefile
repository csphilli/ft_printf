# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:59:38 by cphillip          #+#    #+#              #
#    Updated: 2020/01/17 20:55:55 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a
# need to move a copy of libft.h to includes
COMP = gcc -Wall -Wextra -Werror $(INCLUDES) -c -o
INCLUDES = -I includes/

SRC_DIR = src/
O_DIR = obj/
LIB_DIR = includes/

C_FILES =	ft_printf.c initializing.c staging.c \
			parse.c checking.c print_c.c print_s_stage.c print_s.c \
			tools.c

FIND_C = $(C_FILES:%=$(SRC_DIR)%)

O_FILES = $(C_FILES:%.c=%.o)

OBJ = $(addprefix $(O_DIR), $(O_FILES))

all: $(O_DIR) $(NAME)

$(NAME): $(OBJ) $(O_DIR)
	@cp $(LIB_DIR)$(LIBFT_A) $(NAME)
	@ar rc $(NAME) $(addprefix $(O_DIR), $(O_FILES))
	@ranlib $(NAME)

$(O_DIR):
	@mkdir -p obj

$(OBJ): $(FIND_C)
	@$(MAKE) $(O_FILES)

$(O_FILES):
	@$(COMP) $(O_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	rm -rf $(addprefix $(O_DIR), $(O_FILES))

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

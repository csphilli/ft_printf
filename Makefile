# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:59:38 by cphillip          #+#    #+#              #
#    Updated: 2020/12/16 13:58:11 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a
COMP = gcc -Wall -Wextra -Werror $(INCLUDES) -c -o
INCLUDES = -I includes/

SRC_DIR = ./src/
O_DIR = ./obj/
LIB_DIR = ./libft/

C_FILES =	ft_printf.c initializing.c staging.c\
			parse.c checking.c print_c.c print_s.c\
			print_p.c print_x.c pre_staging.c print_other.c\
			print_alt.c x_padding.c print_o.c print_u.c print_d.c\
			print_f.c get_numbers.c handle_max.c

FIND_C = $(C_FILES:%=$(SRC_DIR)%)

O_FILES = $(C_FILES:%.c=%.o)

OBJ = $(addprefix $(O_DIR), $(O_FILES))

all: $(O_DIR) $(NAME)

$(NAME): $(OBJ) $(O_DIR)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT_A) .
	@mv	$(LIBFT_A) $(NAME)
	@ar rc $(NAME) $(addprefix $(O_DIR), $(O_FILES))
	@ranlib $(NAME)

$(O_DIR):
	@mkdir -p obj

$(OBJ): $(FIND_C)
	@$(MAKE) $(O_FILES)

$(O_FILES):
	@$(COMP) $(O_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	@echo "Cleaning Object Files..."
	rm -rf $(addprefix $(O_DIR), $(O_FILES))

fclean: clean
	@echo "Deleting binary: $(NAME)"
	rm -rf $(NAME)
	rm -rf $(addprefix $(LIB_DIR), $(LIBFT_A))

re: fclean all

.PHONY: all clean fclean re

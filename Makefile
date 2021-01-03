# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 14:26:38 by cphillip          #+#    #+#              #
#    Updated: 2021/01/03 22:15:41 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

SRC_DIR = ./src/

SRC = 	checking.c ft_printf.c get_numbers.c handle_max.c initializing.c\
		parse.c pre_staging.c print_alt.c print_c.c print_d.c print_f.c\
		print_o.c print_other.c print_p.c print_s.c print_u.c print_x.c\
		staging.c x_padding.c

SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJ_FILES = $(SRC:.c=.o)
OBJ_DIR = obj/

INC = ./includes

all: $(NAME)

$(NAME): $(SRC_FILES) $(INC)/ft_printf.h
	@if git submodule status | egrep -q '^[-]' ; then \
		echo "INFO: Initializing git submodules"; \
		git submodule update --init --recursive; \
	fi
	@echo "Compiling ft_printf..."
	@mkdir -p $(OBJ_DIR)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -c $(SRC_FILES) -I$(INC) -I ./libft/includes
	@ar rc $(NAME) $(OBJ_FILES)
	@ranlib $(NAME)
	@mv $(OBJ_FILES) $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBFT)/obj

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re

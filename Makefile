#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semartin <semartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/12 12:35:21 by semartin          #+#    #+#              #
#    Updated: 2016/04/11 15:58:47 by semartin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fract_ol
SRC_DIR = ./srcs/
SRC = fract_ol.c ft_complexe.c ft_julia.c ft_minilibx.c \
		ft_pixel_put_to_image.c ft_mandelbrot.c ft_cellul.c ft_pythagore.c \
		ft_fnct.c ft_key_event.c ft_mouse_event.c ft_newton.c \
		ft_cellul_1.c ft_cellul_2.c ft_complexe_2.c
VPATH = $(SRC_DIR)
OBJ = $(addprefix $(O_DIR)/,$(SRC:.c=.o))
O_DIR = ./objs
LIB = libft 

all : $(NAME)

$(NAME): $(OBJ)
	@echo "Making library."
	@make -C libft/
	@echo "Library made."
	@echo "Making exe."
	@gcc -o $(NAME) -Werror -Wextra -Wall -Lminilibx -lmlx -L/usr/X11/lib \
		-lXext -lX11 -I includes/ $(OBJ) -L libft/ -lft
	@echo "Exe made."

$(O_DIR)/%.o: %.c
	@cp libft/include/libft.h includes
	@mkdir -p $(O_DIR)
	@gcc -Wall -Werror -Wextra -I includes -o $@ -c $<

clean:
	@echo "Removing objets."
	@rm -f $(OBJ)
	@echo "Clean done."

fclean: clean
	@echo "Removing exe."
	@rm -f $(NAME)
	@echo "Fclean done."

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 23:14:13 by yoelguer          #+#    #+#              #
#    Updated: 2020/02/09 07:25:28 by aelouazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= 	main.c	draw.c draw2.c read_file.c ft_check.c deal_key.c

OB		= $(SRC:.c=.o)

NAME 	= fdf.a

CFLAGS = -Wall -Wextra -Werror

FLAG	= -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OB)
	@make -C ./libft/
	gcc -c $(CFLAGS) $(SRC)
	gcc $(SRC) $(FLAG) libft/libft.a -o fdf

clean :
	@make clean -C ./libft/
	rm -rf $(OB)

fclean : clean
	@make fclean -C ./libft/
	rm -rf $(NAME)
	rm -rf fdf

norme:
	norminette $(SRC)

re : fclean all

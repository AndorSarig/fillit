# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarig <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 15:43:44 by asarig            #+#    #+#              #
#    Updated: 2018/01/22 19:46:51 by rbudai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC	= ft_filechecker.c \
	ft_new_square.c \
	ft_free_matrix.c \
	ft_print_result.c \
	main.c\
	ft_hash_to_alpha.c\
	ft_put_to_array.c\
	ft_reader.c\
	ft_check_pieces.c\
	ft_help.c\
	ft_resolve.c

OBJ	= $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = src/libft/libft.a

FILLITH = src/fillit.h

CC	= @gcc

CFLAG	=	-Wall -Werxtra -Werror

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -I $(FILLITH) -c $(SRC_POS)
$(LIBFT): 
	@make -C ./src/libft/

clean:
	@rm -f $(OBJ)
	@make fclean -C ./src/libft/

fclean:
	@make clean
	@rm -f $(NAME)
	@make fclean -C ./src/libft/

re:
	@make fclean
	@make all


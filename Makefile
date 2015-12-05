# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/03 10:43:37 by zcarde            #+#    #+#              #
#    Updated: 2015/12/05 17:56:45 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = wolf3d
SRC = main.c\
	  wolf_3d.c\
	  ft_strsplit_pp.c\
	  ft_strtrim_pp.c\
	  Getmap/ft_get_map.c\
	  Draw/ft_mlx_fct.c\
	  Draw/ft_draw.c\
	  Draw/ft_wall.c\
	  Draw/ft_floor.c\
	  Draw/ft_ceilling.c\
	  Draw/ft_keys.c\
	  Draw/ft_space.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

LIBS = -Llibft -lft -Lminilibx_macos -lmlx -lm -framework OpenGL -framework AppKit

INC = -I ./libft/includes -I ./includes -I minilibx_macos

# LIBS = -Llibft -lft  -L/usr/X11/lib -lmlx -lXext -lX11

# INC = -I ./libft/includes -I ./includes -I /mini

.PHONY : libft.a

all : libft.a $(NAME)

libft.a:
	@$(MAKE) -C ./minilibx_macos
	@$(MAKE) -C ./libft

$(NAME) : $(OBJ)
	gcc $(FLAG) $(OBJ) $(LIBS) $(INC) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

play :
	@echo "Pour jouer :"
	@echo "	- Deplacez-vous grace aux fleches directionnel"
	@echo "	- Courrez grace a la touche maj"
	@echo "	- Ouvrez les portes avec la touche espace"
	@echo "	- Quittez le jeu avec espace"
	./$(NAME) Map/lvl1.w3d Map/lvl2.w3d Map/lvl3.w3d

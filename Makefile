# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 14:54:43 by bpodlesn          #+#    #+#              #
#    Updated: 2018/04/24 12:24:53 by bpodlesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror -O3

IDIR = ./include

CFLAGS = -I include \
		 -I libSDL/SDL2.framework/Headers \
		 -I libSDL/SDL2_image.framework/Headers 

LIBFT = libft

SDL2_F		= -framework SDL2 -framework SDL2_image -F ./libSDL/

SDL2_P		= -rpath @loader_path/libSDL/

DIR_S = src

DIR_O = obj

HEADER = include

_DEPS = wolf.h

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SOURCES =  main.c \
           check_error.c \
           create_textures.c \
           key.c \
           original.c \
           reader.c \
           set_par.c \
           tex_hud.c \
           move_weap_and_shift.c \
           calc.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS)  libft/libft.a $(SDL2_P) $(SDL2_F)

obj:
		mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

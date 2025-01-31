NAME = so_long
SRCS = src/mlx.c src/cheching.c src/put_image.c src/validating.c src/movement.c src/flood_fill.c src/exit.c
OFILES =  $(SRCS:src/%.c=obj/%.o)
lib = libft/libft.a
lib_path=./libft
CFLAG = -Wall -Wextra -Werror -g -L$(lib_path) -lft -L/usr/local/lib -lmlx -I/usr/local/include -L/usr/local/lib/x86_64-linux-gnu -lXext -lX11 -I. -Ilibft


all: $(lib) $(NAME)

$(lib):
	make -C $(lib_path)

$(NAME): $(OFILES)
	cc $^ $(CFLAG) -g -o $@

obj/%.o: src/%.c
	mkdir -p obj
	cc $(CFLAG) -c $< -o $@

clean :
		make -C $(lib_path) clean
		rm -f $(OFILES)
		rm -rf obj

fclean : clean
		make -C $(lib_path) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re LIB

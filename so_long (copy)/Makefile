NAME = so_long
SRCS = src/mlx.c src/exit_handler.c src/cheching.c src/put_image.c src/validpath.c src/moving.c
OFILES =  $(SRCS:src/%.c=obj/%.o)
lib = libft/libft.a
lib_path=./libft
CFLAG = -Wall -Wextra -Werror -g -L$(lib_path) -lft -L/usr/local/lib -lmlx -I/usr/local/include -L/usr/local/lib/x86_64-linux-gnu -lXext -lX11 -I. -Ilibft


all: $(lib) $(NAME)

$(lib):
	make -C $(lib_path)

$(NAME): $(OFILES)
	cc $^ $(CFLAG) -o $@

obj/%.o: src/%.c
	cc $(CFLAG) -c $< -o $@

NAME = so_long
OFILES = obj/mlx.o obj/exit_handler.o obj/cheching.o
lib = libft/libft.a
lib_path=./libft

all: $(lib) $(NAME)

$(lib):
	make -C $(lib_path)

$(NAME): $(OFILES)
	cc $^ -o $@ -L$(lib_path) -lft -lmlx -lXext -lX11

obj/%.o: src/%.c
	cc -Wall -Wextra -Werror -g -c $< -o $@ -I inc -I $(lib_path)

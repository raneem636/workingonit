NAME = so_long
OFILES = obj/mlx.o obj/exit_handler.o

all: $(NAME)

$(NAME): $(OFILES)
	cc $^ -o $@ -lmlx -lXext -lX11

obj/%.o: src/%.c
	cc -Wall -Wextra -Werror -c $< -o $@ -I inc
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

OBJS = $(SRC:.c=.o)
SRC =	command.c push_swap.c utils.c sorting.c node.c checking.c
NAME = push_swap
LIBSRC = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c \
	ft_memset.c\
	ft_strlen.c\
	ft_bzero.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_strdup.c\
	ft_memchr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_itoa.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_split.c
LIBSRC := $(addprefix $(LIBDIR)/, $(LIBSRC))
all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB): $(LIBSRC)
	$(MAKE) -C $(LIBDIR)
$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)


clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
$(LIB): $(wildcard $(LIBDIR)/*.c) $(wildcard $(LIBDIR)/*.h)
.PHONY: all clean fclean re
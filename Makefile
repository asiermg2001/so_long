NAME = so_long
SOURCES = main.c readmap.c mapcontent.c Errors/minimumserror.c freemap.c \
Errors/argerrors.c mapcheck.c Errors/rectangleerror.c mapcomprobations.c \
checkinvalidchars.c Errors/invalidcharserror.c checkmapclosed.c \
Errors/mapnotclosederror.c startgame.c exitgame.c mappath.c startmap.c \
movement.c Errors/mappathinvalid.c
OBJ = $(SOURCES:.c=.o)
SANITIZE = -fsanitize=address
CC = cc
CFLAGS = -Wall -Wextra -Werror #$(SANITIZE)


all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C ft_printf
	$(MAKE) -C mlx 
	rm -f logs
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx $(OBJ) ft_printf/libftprintf.a Libft/libft.a mlx/libmlx.a -o $(NAME)

clean :
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C ft_printf
		make clean -C mlx

fclean : clean
		make fclean -C libft
		make fclean -C ft_printf
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME	=	libftprintf.a

LIB		=	libft.a

EXEC	=	prgm

SRC		=	ft_printf.c		\
			conversions.c

MAIN	=	main.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

RM		=	rm -f

$(NAME)	:	$(OBJ)
			make -C libft
			cp libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ)

%.o		: 	%.c
			$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)
			echo "test"

clean	:
			$(RM) $(OBJ)

prgm	:	all
			$(CC) $(CFLAGS) $(MAIN) -o $(EXEC) -L. $(NAME) $(LIB)

fclean	:	clean
			$(RM) $(NAME) $(EXEC) $(LIB)

re		:	fclean all

.PHONY	:	all prgm clean fclean re lfclean fclean
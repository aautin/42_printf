NAME	=	libftprintf.a

EXEC	=	prgm

LIB		=	libft/libft.a

SRC		=	ft_printf.c		\
			conversions.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

$(LIB)	:
			make -C libft

$(NAME)	:	$(OBJ)
			@echo 'test'
			ar -rc -o $@ $(OBJ)  -l ft 

%.o		: 	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I libft

all		:	$(LIB) $(NAME)

clean	:
			$(RM) $(OBJ)

lclean	:
			$(RM) $(OBJ)
			make -C libft clean

prgm	:	all
			$(CC) $(CFLAGS) -o $(EXEC) $(NAME) -Llibft -lft

fclean	:	clean
			$(RM) $(NAME)

lfclean	:	lclean
			$(RM) $(NAME)
			make -C libft fclean

re		:	fclean all

.PHONY	:	all libft prgm clean fclean re lfclean fclean
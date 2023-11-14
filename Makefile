NAME	=	libftprintf.a

EXEC	=	prgm

LIB		=	../libft/libft.a

SRC		=	ft_printf.c		\
			conversions.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

$(LIB)	:
			cd libft && make

$(NAME)	:	$(OBJ)
			ar -rc -o $@ $(OBJ) -L/libft

%.o		: 	%.c
			$(CC) $(CFLAGS) -c $< -o $@ 

all		:	$(LIB) $(NAME)

.PHONY	:	all clean fclean re

clean	:
			$(RM) $(OBJ)

prgm	:	$(LIB) $(NAME)
			$(CC) $(CFLAGS) -o $(EXEC) $(LIB) -L/libft $(NAME)

fclean	:	clean
			$(RM) $(NAME)	

re		:	fclean all
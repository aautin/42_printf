NAME	=	libftprintf.a

SRC		=	src/bonus_ft_printf.c	\
			src/bonus_putctag.c		\
			src/bonus_putstag.c		\
			src/bonus_putxtag.c		\
			src/bonus_putptag.c		\
			src/bonus_putdtag.c		\
			src/bonus_pututag.c		\
			src/bonus_tags.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

RM		=	rm -f

$(NAME)	:	$(OBJ)
			make -C libft
			cp libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ)

all		:	$(NAME)

%.o		: 	%.c
			$(CC) $(CFLAGS) -c $< -o $@

bonus	:	all

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
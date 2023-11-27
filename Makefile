NAME	=	libftprintf.a

SRC		=	bonus_ft_printf.c	\
			bonus_putctag.c		\
			bonus_putstag.c		\
			bonus_putxtag.c		\
			bonus_putptag.c		\
			bonus_putdtag.c		\
			bonus_pututag.c		\
			bonus_tags.c

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
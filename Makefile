NAME	=	libftprintf.a

EXEC	=	prgm

SRC		=	ft_printf.c		\
			conversions.c

SRC_B	=	bonus_ft_printf.c	\
			bonus_char.c		\
			bonus_tags.c

MAIN	=	main.c

MAIN_B	=	bonus_main.c

OBJ		=	$(SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

RM		=	rm -f

$(NAME)	:	$(OBJ)
			make -C libft
			cp libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ)

bonus	:	$(OBJ_B)
			make -C libft
			cp libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ_B)

%.o		: 	%.c
			$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)

clean	:
			$(RM) $(OBJ) $(OBJ_B)

prgm	:	all
			$(CC) $(MAIN) -o $(EXEC) -L. $(NAME)

prgm_b	:	bonus
			$(CC) $(MAIN_B) -o $(EXEC) -L. $(NAME)

fclean	:	clean
			$(RM) $(NAME) $(EXEC)

re		:	fclean all

.PHONY	:	all prgm clean fclean re bonus
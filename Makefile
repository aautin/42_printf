NAME	=	libftprintf.a

SRCS	=	ft_printf.c		\
			conversions.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJS)
			ar rcs $@ $(OBJS)

%.o		: 	%.c
			$(CC) $(CFLAGS) -c $< -o $@ 

all		:	$(NAME)

.PHONY	:	all clean fclean re

clean	:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
			$(RM) $(NAME)	

re		:	fclean all
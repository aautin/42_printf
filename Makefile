NAME	=	libftprintf.a

SRCS	=	ft_printf.c		\
			conversions.c	\

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJS)

%.o		:	%c
			$(CC) -c -o $@ $< $(CFLAGS)
			ar rcs $(NAME) $@

all		:	$(NAME)
			$(CC) $(OBJS) $(NAME) $(CFLAGS)

.PHONY	:	all clean fclean re

clean	:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
			$(RM) $(NAME)	

re		:	fclean 
			make
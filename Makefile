NAME	=	libftprintf.a

LDFLAGS	=	-L/home/aautin/Code/ft_printf/libft

LDLIBS	+=	-lft

SRCS	=	ft_printf.c		\
			conversions.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJS)
			ar rcs $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

%.o		: 	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

all		:	$(NAME)

.PHONY	:	all clean fclean re

clean	:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
			$(RM) $(NAME)	

re		:	fclean 
			make
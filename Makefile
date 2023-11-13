NAME	=	libftprintf.a

LDFLAGS	=	-L/home/aautin/Code/ft_printf/

LDLIBS	+=	-lft

SRCS	=	ft_printf.c		\
			conversions.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJS)
			$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
			ar rcs $@ $(OBJS)

%.o		:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

all		:	$(NAME)

.PHONY	:	all clean fclean re

clean	:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
			$(RM) $(NAME)	

re		:	fclean 
			make
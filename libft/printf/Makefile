SRCS	=	ft_printf.c srcs/ft_base10.c srcs/ft_hex.c srcs/ft_put.c

OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

INCLUDES = -I./includes

NAME	=	libftprintf.a

.c.o:
		@$(GCC) $(FLAGS) -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			@ar rcs $@ $^
			@echo '\033[1;35mPrintf created! 🥳';

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

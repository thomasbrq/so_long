SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_atoi.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

.c.o:
		@$(GCC) $(FLAGS) -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			@$(MAKE) -C ./printf
			@cp printf/libftprintf.a $(NAME)
			@ar rcs $@ $^
			@echo '\033[1;35mLibft created! 🥳';

all:		$(NAME)

clean:
			@$(RM) $(OBJS) libftprintf.a
			@$(MAKE) clean -C ./printf
			@echo '\033[1;37mCleaning!... 🧹';

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C ./printf
			@echo '\033[1;37mAll is clean!... 🧹';

re:			fclean all

.PHONY:		all clean fclean re

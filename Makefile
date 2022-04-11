SRCS	=	main.c srcs/window.c srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c srcs/errors.c \
			srcs/map/map.c srcs/map/map_utils.c srcs/map/map_errors.c \
			srcs/player/player.c srcs/draw.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

NAME	=	so_long

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# %.o: %.c
# 	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C ./mlx
			@$(MAKE) -C ./libft
			@cp mlx/libmlx.a .
			@cp libft/libft.a .
			@$(CC) $(OBJS) -Lmlx -lmlx libft.a -framework OpenGL -framework AppKit -o $(NAME)
			@echo '\033[1;35mSo_long created! 🎮';

# LINUX:	$(OBJS)
# 		@$(MAKE) -C ./libft
# 		@cp libft/libft.a .
# 		@$(CC) $(OBJS) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
# 		@echo '\033[1;35mSo_long created! 🎮';

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@$(MAKE) clean -C ./mlx
			@$(MAKE) clean -C ./libft
			@echo '\033[1;37mCleaning!... 🧹';

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C ./libft
			@$(RM) libmlx.a
			@$(RM) libft.a
			@echo '\033[1;37mAll is clean!... 🧹';

re:			fclean all

.PHONY:		all clean fclean re

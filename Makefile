NAME      	= cub3D
SRCS      	= $(wildcard ./game/*.c ./parse/*.c)
OBJS      	= $(SRCS:.c=.o)
CC			= cc
INCLUDE 	= -I./headers -I./mlx
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g3
M_FLAGS		= -Lmlx -lmlx  -framework OpenGL -framework AppKit  #-Lmlx

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -Imlx -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(M_FLAGS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

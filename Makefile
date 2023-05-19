NAME      	= cub3D
SRCS      	= $(wildcard ./game/*.c ./parse/*.c)
OBJS      	= $(SRCS:.c=.o)
CC			= cc
INCLUDE 	= -I./headers #-I./mlx
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
M_FLAGS		= -lmlx  -framework OpenGL -framework AppKit  #-Lmlx

%.o : %.c  Makefile
	@$(CC) $(CFLAGS) $(INCLUDE) -Imlx -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(M_FLAGS) -o $(NAME)
	@echo "$(GRN)$(NAME) Created!$(DEF)"

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)All deleted!$(DEF)"

re : fclean all

.PHONY: all clean fclean re

RED = \033[0;31m
GRN = \033[0;32m
DEF = \033[0m
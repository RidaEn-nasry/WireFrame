MAKEFLAGS += --silent


NAME	=	fdf

SRCS	=	srcs/main.c \
			srcs/read.c \
			srcs/draw.c \
			srcs/drawing_tools.c \
			srcs/errors.c\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

M_FLAGS	=	-lmlx -framework AppKit -framework OpenGL

LIBFT_GNL  = libraries/libft/libft.a libraries/get_next_line/*

all: $(clean) $(NAME)

$(NAME):	$(OBJS) $(SRCS)
			@make -C libraries/libft/
			@gcc $(CFLAGS) $(OBJS) $(M_FLAGS) $(LIBFT_GNL) -o $(NAME)


clean:
		@rm -rf $(OBJS)
		@cd ./libraries/libft && make clean 


fclean:	
		@rm -rf $(NAME) $(OBJS)
		@cd ./libraries/libft && make fclean

re:			clean all

.PHONY:		re clean fclean all

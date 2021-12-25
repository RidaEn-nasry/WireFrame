
NAME	=	libft.a

SRCS	=	ft_atoi.c		\
			ft_error.c		\
			ft_free_tab.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_strcpy.c		\
			ft_split.c		\
			ft_strlen.c		\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			@rm -rf $(OBJS)

fclean:
			@rm -rf $(NAME) $(OBJS)

re:			fclean all

.PHONY:		clean fclean all re

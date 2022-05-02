NAME 	= 	pipex

SRCS 	=	pipex.c		\
			utils.c		\
			utils2.c

CC 		= 	gcc

OBJS 	= 	$(SRCS:.c=.o)

FLAGS 	= 	-Wall -Werror -Wextra

.c.o	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	: 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

all		: 	$(NAME)

clean	:
			rm -rf $(OBJS)

fclean	: 	clean
			rm -rf $(NAME)

re		: 	fclean all

.PHONY	: 	clean fclean re all

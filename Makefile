NAME = minishell

SRCS = torkanizer/torkanizer.c\
		parser/parser.c\
		utils/compare_string.c utils/split.c utils/ft_strlen.c\
		main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(SRCS) -lreadline -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY:		all clean fclean re bonus
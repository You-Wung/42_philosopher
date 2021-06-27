  
NAME = philo_bonus

CC = gcc

CFLAGS = -Werror -Wall -Wextra -lpthread

RM = rm -rf

SRCS =	main.c\
		destory.c\
		time_msg.c\
		eat.c\
		forks.c\
		init.c\
		utils.c

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all
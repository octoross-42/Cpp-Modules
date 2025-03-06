NAME = sed

SRCS = main.cpp \

CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -I./ -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean 
	@rm -f $(NAME)
	

re: fclean all

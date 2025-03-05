NAME = zombie

SRCS = randomChump.cpp \
		newZombie.cpp \
		Zombie.cpp \
		main.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}	

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean 
	@rm -f $(NAME)
	

re: fclean all
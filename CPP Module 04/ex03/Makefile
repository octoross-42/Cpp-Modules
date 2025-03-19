NAME = materials

SRCS = AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
		MateriaSource.cpp \
		main.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g3

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -I./ -c $< -o ${<:.cpp=.o}	

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean 
	@rm -f $(NAME)
	

re: fclean all
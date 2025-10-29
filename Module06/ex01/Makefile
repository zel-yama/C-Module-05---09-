NAME = program
COM = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = Serializer.cpp main.cpp
OBJ = $(FILES:.cpp=.o)
RM = rm -rf
HEADER = Serializer.hpp Data.h

all: $(NAME)
%.o: %.cpp $(HEADER)
	$(COM) $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all 
	
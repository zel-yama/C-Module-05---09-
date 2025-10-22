NAME = program
COM = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = Bureaucrat.cpp main.cpp
OBJ = $(FILES:.cpp=.o)
RM = rm -rf
HEADER = Bureaucrat.hpp

all: $(NAME)
%.o: %c $(HEADER)
	$(COM) $(FLAGS) $< -o $@
$(NAME):
	$(COM) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

	
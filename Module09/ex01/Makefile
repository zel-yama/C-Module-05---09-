
NAME = RPN 
FLAGS = -Werror -Wextra -Wall -std=c++98
COM = c++
RM = rm -rf 
FILES = main.cpp RPN.cpp
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp RPN.hpp 
	$(COM) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ);
fclean: clean 
	$(RM) $(NAME)
re: fclean all 
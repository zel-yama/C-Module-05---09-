
NAME = PmergeMe
COM = c++ 
FILES = PmergeMe.cpp main.cpp 
FLAGES = -Werror -Wextra -Wall 
RM = rm -rf 
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp 
	$(COM) $(FLAGES) -c  $< -o $@
all: $(NAME)
	
$(NAME): $(OBJ)
	$(COM) $(FLAGES)  $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean	
	$(RM) $(NAME)
re: fclean all 


NAME = PmergeMe
COM = c++ 
FILES = PmergeMe.cpp main.cpp dequeSorted.cpp vectorSorted.cpp
FLAGES = -Werror -Wextra -Wall #-std=c++98
RM = rm -rf 
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp  PmergeMe.hpp
	$(COM) $(FLAGES) -c  $< -o $@
all: $(NAME)
	
$(NAME): $(OBJ)
	$(COM) $(FLAGES)  $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean	
	$(RM) $(NAME)
re: fclean all 

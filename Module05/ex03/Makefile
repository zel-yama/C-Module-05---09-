NAME = program
COM = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJ = $(FILES:.cpp=.o)
RM = rm -rf
HEADER = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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
NAME = btc
COM = c++
FLAGS = -Wall -Werror -Wextra #-std=c++98
FILES =  BitcoinExchange.cpp main.cpp parsing.cpp
OBJ = $(FILES:.cpp=.o)
HEADER = BitcoinExchange.hpp
RM = rm -rf 

%.o:%.cpp 
	$(COM) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all 
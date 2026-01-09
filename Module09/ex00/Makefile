NAME = btc
COM = c++
FLAGS = -Wall -Werror -Wextra 
FILES =  BitcoinExchange.cpp main.cpp
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

#include "PmergeMe.hpp"

int main(int ac, char *av[]){
    PmergeMe V1;
    try{
        parsing(ac, av, V1);
    }   
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
        return 1;
    }

}
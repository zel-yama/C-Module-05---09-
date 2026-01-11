#include "RPN.hpp"

int main(int ac, char *av[]){

    RPN obj;
    if (ac != 2){
        std::cerr << "Error invalid arguements " << std::endl;
        return 1;
        
    }
    try{
        obj.operations(av[1]);
        
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}
#include "BitcoinExchange.hpp"
int main(int av, char *ac[])
{
    (void) ac;
    
    if (av != 2)
    return (1);
    try{
        BitcoinExchange obj;

    } 
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
        return 1;
    }
}
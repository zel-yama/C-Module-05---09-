
#include "ScalarConverter.hpp"

int main(int av, char *ac[]){


    if (av == 2){
        try{

            ScalarConverter::convert(ac[1]);
        }
        catch (ScalarConverter::ExceptionError &e)
        {
            std::cout << e.what() << std::endl;
        }
        }
}
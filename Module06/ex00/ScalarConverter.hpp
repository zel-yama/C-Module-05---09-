#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
class ScalarConverter{

    public:
        static void convert(std::string literal);
        class ExceptionError : std::exception{
            public:
                const char *what() const throw();
        };
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);
        static float IntToFloat(int val);
        static void handle_double(std::string str);
        static double IntToDouble(int val);
        static void handle_float(std::string str);
        static void handle_char(char c);
        static void handle_int(int num);
        static void print_char(int c);
        static void handle_inff(std::string str);
        static void handle_inf(std::string str);
        static void CheckValue(std::string str);


};
#endif
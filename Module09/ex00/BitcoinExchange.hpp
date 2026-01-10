#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
#include <cctype>
typedef std::map<std::string , float> maptype;
class BitcoinExchange{
    public:
        std::string date;
        int  value;
        bool flag;
        BitcoinExchange();
        maptype store;
    private:
    
        
};
std::string removeSpaces(std::string &str);
int convertString(std::string &str);
void parsing(char *file, BitcoinExchange &obj);
 #endif
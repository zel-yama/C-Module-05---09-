#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
#include <cctype>
class BitcoinExchange{
    public:
        size_t year;
        size_t day;
        
        size_t month;
        bool flag;
        BitcoinExchange();
    private:
        std::map<std::string , float> store;
    
        
};
std::string removeSpaces(std::string &str);

 #endif
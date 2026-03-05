

#include "BitcoinExchange.hpp"

double convertString(std::string &str){
    
    std::stringstream ss(str);
    std::string s;
    double value;
    ss >> value;
    ss >> s;

    if (!s.empty() || !ss.eof())
        return -1;
    else 
        return value;
}

std::string removeSpaces(std::string &str){

  
	size_t end = str.size() ;
	size_t start = 0;
	while(start < end && std::isspace((unsigned char)str[start]))
		start++;
	while(start < end && std::isspace((unsigned char)str[end-1]))
		end--;
	return str.substr(start, (end - start));
}

BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj ){
    (void )obj;

    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
    (void)obj;
}

BitcoinExchange::BitcoinExchange(){

    flag = false;
    std::ifstream data("data.csv");
    std::string str;
    std::string key;
    float value;
    this->value = 0.00;
    while(getline(data, str)){
     
        if (!str.compare("date,exchange_rate")){
            continue;
        }
        else {
            size_t pos = str.find(",");
            key = str.substr(0, pos);
            pos++;
            str = str.substr(pos);
            value = convertString(str);
        
            store[key] = value;            
        }   
    }
}
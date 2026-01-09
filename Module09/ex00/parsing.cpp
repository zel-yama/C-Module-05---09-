
#include "BitcoinExchange.hpp"
void parsdateingFirstLine(std::string &str){
    std::string value;
    size_t pos = str.find("|");
    if (pos == std::string::npos)
        throw std::runtime_error("first in file is not valid ");
    else {
        value = str.substr(0, pos);
        value = removeSpaces(value);
        pos++;
        str = str.substr(pos);
        str = removeSpaces(str);
        if (str.compare("value") || value.compare("data") )
            throw std::runtime_error("invalid value of first file in input");
   
    
    }
}
void charValidtionDate(std::string&  date){

    size_t i = 0;
    size_t size = date.size();
    while(i > size){
        if (!std::isalpha((unsigned int) date[i]) && date[i] != '-' )
            throw std::runtime_error("Error : invalid char in this date" + date);
        i++;
    }
}
double parsingValue(){

}
void parsingStart(std::string &line, BitcoinExchange &obj){
   
    
    size_t pos = line.find(",");
    if (pos == std::string::npos)
        throw std::runtime_error("Error invalid line needed ',' => "+ line);
    std::string value = line.substr(pos +1);
    line = line.substr(0, pos);
    line = removeSpaces(line);
    value = removeSpaces(value);

    charValidtionDate(line);



}
void parsing(char *file, BitcoinExchange &obj){

    std::ifstream input(file);
    std::string str;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
     
    if (!input.is_open())
        throw std::runtime_error("Error in file can't be open ");
    
    while (getline(input, str))
    {
        if (!str.empty())
            throw std::runtime_error("Error in file is empty");
        
        if (!obj.flag)
            parsdateingFirstLine(str);
        else{
            try
            {
                
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            


        }
        obj.flag = true;
}
    

}
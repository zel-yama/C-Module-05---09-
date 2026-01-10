
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
     
        if (str.compare("value") != 0 || value.compare("date") != 0 )
            throw std::runtime_error("invalid value of the first line in  file in input");
   
    
    }
}
void convertValue(std::string &date){
    char dash, dash1;
    int day,year, month;
    //int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
    std::stringstream ss(date);
    ss >> year >> dash >> month >> dash1 >> day;
    if ((day == 0 || month == 0) ||  year == 0 )
        throw std::runtime_error("invalid value => " + date);
}

void charValidtionDate(std::string&  date){

    size_t i = 0;
    size_t size = date.size();
    while(i > size){
        if (!std::isalpha((unsigned int) date[i]) && date[i] != '-' )
            throw std::runtime_error("Error : invalid char in this date => " + date);
        i++;
    }
    if (date[0] == '-' || date[size -1] == '-')
        throw std::runtime_error("Error: invalid date => "+ date);
    convertValue(date);
}
void parsingValue(std::string &value){
    size_t i = 0;
    size_t size = value.size();
    while(i < size){
 
        if (std::isalpha((unsigned int) value[i]) && value[i] != '.' )
            throw std::runtime_error("Error value is not valid => " + value);
        i++;
    }

}
void parsingStart(std::string &line, BitcoinExchange &obj){
    
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        throw std::runtime_error("Error invalid line needed ',' => "+ line);
    std::string value = line.substr(pos +1);
    line = line.substr(0, pos);
    line = removeSpaces(line);
    value = removeSpaces(value);
    obj.date = line;
    obj.value = convertString(value);
    parsingValue(value);
    charValidtionDate(line);
    if (obj.store.begin()->first > line)
        throw std::runtime_error("bad input => " + line);

}
void print(std::string &date, int price, int result){
    std::cout << date << " => " << price << " = " << result << std::endl;
}

void findValue(BitcoinExchange &obj){

    if(obj.store.find(obj.date) != obj.store.end())
    {
        print(obj.date, obj.value, obj.value * obj.store[obj.date] );
    }
    else{

        maptype::iterator its = obj.store.end();
        its--;
        if (obj.date > its->first)
            print(obj.date, obj.value, obj.value * obj.store.end()->second);
        else{
            maptype::iterator it = obj.store.lower_bound(obj.date);
            it--;
            printf("%d -- %f\n", obj.value, it->second);
            print(obj.date, obj.value, obj.value * it->second);
        }
    }

}

void parsing(char *file, BitcoinExchange &obj){

    std::ifstream input(file);
    std::string str;
    

    if (!input.is_open())
        throw std::runtime_error("Error in file can't be open ");
    
    while (getline(input, str))
    {
        if (str.empty())
            throw std::runtime_error("Error in file is empty");
        
        if (!obj.flag)
            parsdateingFirstLine(str);
        else{
            try
            {
                parsingStart(str, obj);
                findValue(obj);

            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            


        }
        obj.flag = true;
}
    

}
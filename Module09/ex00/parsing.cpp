
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

void checkDate(std::string &date){
    char dash, dash1;
    int day,year, month;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
    std::stringstream ss(date);
    ss >> year >> dash >> month >> dash1 >> day;
    if (dash != '-' || dash1 != '-')
        throw std::runtime_error("Error : invalid needed tow dash => " + date);
    if (year % 400 == 0 || year % 4 == 0)
        daysInMonth[1] = 29;
    if ((day <= 0 || month <= 0) ||  year <= 0 )
        throw std::runtime_error("Error : invalid date => " + date);
    if (month > 12)
        throw std::runtime_error("Error : invalid month => "+ date);
    if (daysInMonth[month -1] < day)
        throw std::runtime_error("Error : day is too large => "+ date);
}

void charValidtionDate(std::string&  date){

    size_t size = date.size();
    if (size != 10)
        throw std::runtime_error("Error: format of date is not correct => " + date);
    if (date[0] == '-' || date[size -1] == '-')
        throw std::runtime_error("Error: invalid date => "+ date);
    checkDate(date);
}

void checkTokens(std::string &line){
    size_t i = 0;

    while (i < line.size())
    {
        if (std::isspace((unsigned int ) line[i]) != 0 || std::isdigit((unsigned int ) line[i]) != 0 )
        {
        } 
        else if (line[i] != '-' && line[i] != '|' && line[i] != '.'){
        
            throw  std::runtime_error("Error tokens should be valid => " + line);
        }
        i++;
    }
    
}
void parsingStart(std::string &line, BitcoinExchange &obj){
    
    checkTokens(line);
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        throw std::runtime_error("Error invalid line needed '|' => "+ line);
    std::string value = line.substr(pos + 1);
    line = line.substr(0, pos);
    line = removeSpaces(line);
    value = removeSpaces(value);
    obj.date = line;
    obj.value = convertString(value);
    if (obj.value < 0 )
        throw std::runtime_error("Error: is not  valid number. => "+ line);
    if (obj.value > 1000)
        throw std::runtime_error("Error: too large a number.=> "+ line);
    charValidtionDate(line);
    if (obj.store.begin()->first > line)
        throw std::runtime_error("Error : lower date for my data range => " + line);
}
void print(std::string &date, double price, double result){
    std::cout << date << " => " << price << " = " << result << std::endl;
}

void findValue(BitcoinExchange &obj){


    if(obj.store.find(obj.date) != obj.store.end())
    {
        print(obj.date, obj.value,(double) obj.value * obj.store[obj.date] );
    }
    else{
        maptype::iterator its = obj.store.end();
        its--;
        if (obj.date > its->first)
            print(obj.date, obj.value, (double) obj.value * its->second);
        else{
            maptype::iterator it = obj.store.lower_bound(obj.date);
            it--;
            print(obj.date, obj.value, (double) obj.value * it->second);
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
        if (str.empty()){
            std::cout << " Error empty line -" <<std::endl;
            if (!obj.flag)  
                return ;
            continue;
        }
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
                std::cout << e.what() << '\n';
            } 
        }
        obj.flag = true;
    }
    if (obj.flag == false)
        std::cout << "Error: empty file" <<std::endl;

}
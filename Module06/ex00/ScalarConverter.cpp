


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){

}
ScalarConverter::~ScalarConverter(){

}
ScalarConverter::ScalarConverter(const ScalarConverter &obj){
 (void)obj;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj){
    (void)obj;
    return (*this);
}

void ScalarConverter::print_char(int c){
    if ((c < 32 && c >= 0) || c == 127)
        std::cout << "char   : Non displayable"<< std::endl;
    else if (c > 127 || c < 0)
        std::cout << "char   : impossible" << std::endl;
    else
        std::cout << "char   : " << static_cast<char>(c) << std::endl;
}



void ScalarConverter::handle_char(char c){

    print_char(c);
    std::cout << "int    : " << static_cast<int>(c) << std::endl;
    std::cout << "float  : " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}
void ScalarConverter::handle_int(std::string str){

    int num;
    std::stringstream ss(str);
    
    if  (!(ss >> num) || !ss.eof())
        throw ExceptionError();
    print_char(num);
    float res = IntToFloat(num);
    std::cout << "int    : " << num << std::endl;
    std::cout << "float  : " <<  res << "f" << std::endl;
    std::cout << "double : " << IntToDouble(num) << std::endl;

}
void ScalarConverter::handle_float(std::string str){

    float val = 0;
    
    std::string newStr = str.substr(0, str.size() - 1);
    std::stringstream ss(newStr);
    
    if  (!(ss >> val) || !ss.eof())
        throw ExceptionError();
    print_char(static_cast<int> (val));
    std::cout << "int    : " << static_cast<int>(val) << std::endl;
    std::cout << "float  : " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(val) << std::endl;

}
float ScalarConverter::IntToFloat(int val){
    float F_val = static_cast<float> (val);
    return (F_val);
}

double ScalarConverter::IntToDouble(int val){
    double D_val = static_cast<double> (val);
    return (D_val);
}

void ScalarConverter::handle_double(std::string str){
    double val = 0;
    std::stringstream ss(str);
    if  (!(ss >> val) || !ss.eof())
        throw ExceptionError();
    print_char(val);
    float f_val = static_cast<float>(val);
    std::cout << "int    : " <<  static_cast<int>(val)<< std::endl;
    std::cout << "float  : "<<  static_cast<float> (f_val) << "f"  << std::endl;
    std::cout << "double : " << val << std::endl;
    

}

const char *ScalarConverter::ExceptionError::what()const throw(){
    return ("error invalid input");
}

void ScalarConverter::handle_inf(std::string str){
    std::string array[] = {"-inf", "+inf", "nan"};
    int i = 0;
    
    while (i < 3)
    {
        if(!array[i].compare(str))   
            break;
        i++;
    }  
    std::cout << "char   : impossible" << std::endl;
    std::cout << "int    : impossible" << std::endl;
    std::cout << "float  : " << array[i] << "f" << std::endl; 
    std::cout << "double : " << array[i] << std::endl;
}
void ScalarConverter::handle_inff(std::string str){
    std::string array[] = {"-inff", "+inff", "nanf"};
    int i = 0;
    
    while (i < 3)
    {
        if(!array[i].compare(str))   
            break;
        i++;
    }  
    std::cout << "char   : impossible" << std::endl;
    std::cout << "int    : impossible" << std::endl;
    std::cout << "float  : " << array[i] << std::endl;
    std::cout << "double : " << array[i].substr(0, array[i].size() -1) << std::endl; 

}
void ScalarConverter::CheckValue(std::string str){

    if (!str.compare("nan") || !str.compare("-inf")|| !str.compare("+inf"))
        handle_inf(str);
    else if (!str.compare("nanf") || !str.compare("-inff") || !str.compare("+inff"))
        handle_inff(str);
    else
        throw ScalarConverter::ExceptionError();
}

bool IsNumber(std::string num){
    int i = 0;
    if (num[i] == '+' || num[i] == '-')
        i++;
    while(i < (int)num.size()){
        if (!std::isdigit(num[i]))
            return(false);
        i++;
    }
    return true;
}
int CountFractions(std::string str){
    
    if (!strchr(str.c_str(), '.'))
        return 1;
    int count = 0;
    int i = 0;
    while (str[i] != '.'){
        i++;
    }
    if ((str[i] == '.' && str[i + 1] == 'f') || (str[i] == '.' && str[i + 1] == '\0'))
        throw ScalarConverter::ExceptionError();
    i++;
    while ((int)str.size() > i){
        count++;
        i++;
    }
    if (count == 0)
        return 1;
    return(count);
}

void ScalarConverter::convert(std::string literal){

   std::cout << std::fixed << std::setprecision(CountFractions(literal)) ;
    if (literal.size() == 1 && !std::isdigit(literal[0]))
        handle_char(literal[0]);
    else if(IsNumber(literal)) 
        handle_int(literal) ;
    else if (strchr(literal.c_str(), '.') && strchr(literal.c_str(), 'f'))
        handle_float(literal);
    else if (strchr(literal.c_str(), '.'))
            handle_double(literal);
    else 
        CheckValue(literal);    
}

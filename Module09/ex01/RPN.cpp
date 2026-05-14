
#include "RPN.hpp"

RPN::RPN(const RPN &obj){
    (void)obj;
}
RPN::RPN(){

}
RPN::~RPN(){

}
RPN &RPN::operator=(const RPN &obj){

    (void)obj;
    return *this;
}
int switchCases(long num, long num1, char c){
    
    long long res = 0;
    if (num1 == 0 && c == '/')
        throw std::runtime_error("Error division by zero is not allowed ");
    
    switch (c)
    {
        case '*':
            res = num * num1;
            break;
        case '/':
            res = num / num1;
            break;
        case '+':
            res = num + num1;
            break;
        case '-':
            res = num - num1;
            break;
        default:
            throw std::runtime_error("Error : invalid operation {/*+-}");
            break;
    }
    if (res > 2147483647)
        throw std::runtime_error("Error: the max value exceeded max int");
    return res;
}
void caloperation(std::stack<int> &stak, char c){
    int num1, num;
    if (stak.empty() || stak.size() == 1   ){
        if (stak.size() == 1)
            throw std::runtime_error("Error: every operation should have tow number");
        return ;
    }
    num1 = stak.top();
    stak.pop();
    num = stak.top();
    stak.pop();
    stak.push(switchCases(num, num1, c));

}

void RPN::operations(std::string av){

    
    size_t size = av.size();
    if (av.empty()){
        std::cout << "Error: empty string " << std::endl;
        return;
    }

    for(size_t i = 0; i < size ; i++){
        
        if (!std::isdigit(av[i]) && av[i] != '/' && av[i] != '+' && av[i] != '*' && av[i] != '-' && av[i] != ' '  )
            throw std::runtime_error("invalid character in => " + av );
        if (std::isdigit((unsigned int )av[i])){
            if ((i + 1 < size) && std::isdigit(av[i + 1])) {
                std::cout << "Error : in number should be < 10   " << std::endl;
                return ;
            }
            mystack.push((int)av[i] - '0');
        }
        else if (std::isspace(av[i]))
            continue;
        else{
       
            caloperation(mystack,  av[i]);
        }
    }
    if ( mystack.empty()){
        std::cout << "Error: empty stack " << std::endl;
        return ;
    }
    if (mystack.size() > 1 ){
        std::cout << "Error: invalid insertion of operation " << std::endl;
        return;
    }
    int res = mystack.top();
    std::cout << res << std::endl;
}
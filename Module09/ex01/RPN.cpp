
#include "RPN.hpp"
int switchCases(int num, int num1, char c){
    
    int res;
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
    return res;
}
void caloperation(std::stack<int> &stak, char c){
    int num1, num;
    if (stak.empty())
        return ;
    num = stak.top();
    stak.pop();
    num1 = stak.top();
    stak.pop();
    stak.push(switchCases(num, num1, c));

}

void RPN::operations(std::string av){

    
    size_t size = av.size();
    for(size_t i = 0; i < size ; i++){
        if (!std::isalpha((unsigned int )av[i])){
            
            mystack.push((int)av[i] - '0');
        }
        else{
       
            caloperation(mystack,  av[i]);
        }
    }
    int res = mystack.top();
    std::cout << res << std::endl;
}
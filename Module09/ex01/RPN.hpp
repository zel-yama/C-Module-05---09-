
#ifndef RPN_HPP
#define RPN_HPP 
#include <iostream>
#include <stack>
#include <exception>
#include <cctype>

class RPN{
    private:
        std::stack<int> mystack;
    public:
        void operations(std::string av);
        RPN();
        ~RPN();
        RPN &operator=(const RPN &obj);
        RPN(const RPN &obj);
};


#endif
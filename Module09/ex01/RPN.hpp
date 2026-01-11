
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

};


#endif
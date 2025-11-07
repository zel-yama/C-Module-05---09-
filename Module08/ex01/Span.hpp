
#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
class Span{

    private:
        int *array;
        unsigned int size;
        unsigned int counter;        
    public:
        Span();
        Span(unsigned int len);
        ~Span();
        Span(const Span &obj );
        Span &operator=(const Span & obj);
        void addNumber(unsigned   int value);
         int shortestSpan() const;
        int longestSpan() const ;
        void addNumbers(std::vector<int>::iterator  begin, std::vector<int>::iterator end);
        void displayArray();
    

};

#endif
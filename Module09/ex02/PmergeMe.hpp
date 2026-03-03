
#ifndef PMERGEME_HPP 
#define PMERGEME_HPP 
#include <vector>
#include <iostream>
#include <exception> 
#include <sstream>
#include <deque>
typedef std::vector<int> single;


class PmergeMe{

    public:
        int upairedValue;
       
        single V1; 
        std::deque<int> DEQ;
};
void parsing(int ac, char *av[], PmergeMe &obj);

#endif

#ifndef PMERGEME_HPP 
#define PMERGEME_HPP 
#include <vector>
#include <iostream>
#include <exception> 
#include <sstream>
typedef std::vector<int> single;
typedef std::vector<std::pair<int, int> >  doubleV;

class PmergeMe{

    public:
        int upairedValue;
        doubleV V2;
        single V1; 
        
};
void parsing(int ac, char *av[], PmergeMe &obj);

#endif

#ifndef PMERGEME_HPP 
#define PMERGEME_HPP 
#include <vector>
#include <iostream>
#include <exception> 
#include <sstream>
#include <deque>
#include <sys/time.h>
#include <iomanip>

class PmergeMe{

    public:
        double dequeTime;
        double vectorTime; 
        size_t size;
       
        std::vector<int> V1; 
        std::deque<int> deqe;
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &obj);
};
void parsing(int ac, char *av[], PmergeMe &obj);
std::vector<int> JacobsthalSequenec(int n);
void insertElement(std::vector<int> &v, int element);

void printDeque(std::deque<int> &v);
void mergeInsertionVector(PmergeMe &obj, std::vector<int> &v);
void mergeInsertionDeque(PmergeMe &obj, std::deque<int> &v);
#endif  
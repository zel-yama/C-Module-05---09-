

#include "PmergeMe.hpp"
#include <algorithm>
//  pair and return winners be shore that winner can insert abel 
//  recursion untill size equel tow check if value upaired put value number unpaired var 
//  when recursion reach base case return back with reucrsion  
//
//
//
//
PmergeMe::PmergeMe(){

}

PmergeMe::PmergeMe(const PmergeMe &obj){
    (void)obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj ){

    (void)obj;
    return *this;
}

PmergeMe::~PmergeMe(){

}

double getTimeOfDay(){

    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ( (tv.tv_sec * 1000000.0) +  (double)tv.tv_usec);
    
}
std::vector<int> JacobsthalSequenec(int n){
    
    std::vector<int> v;
    if (n <= 0)
        return v;
    v.push_back(0);
    if (n == 1){
        
        return v;
    }   
    v.push_back(1);
    int i  = 2;
    while (i < n)
    {
        size_t val = v[i - 1]  + 2 * v[i - 2];
        v.push_back(val);
        i++;
    }
    return v;
}

int convertString(std::string str){
    

    std::stringstream ss(str);
    std::string s;
    int value;
    ss >> value;
    ss >> s;

    if (!ss.eof()|| !s.empty() )
        throw std::runtime_error("< Error Incorrect Arguments..!  < " + str + " > > ");
    else 
        return value;
}

void parsing(int ac, char *av[], PmergeMe &obj){
    std::cout <<  std::fixed << std::setprecision(7) ;
    int local;
    if (ac < 2)
        throw std::runtime_error("< Error incorrect arguments...! >");
    else{
        for(int i = 1; i < ac; i++){
          local =  convertString(av[i]);
          if (local < 0)
            throw std::runtime_error("< Error incorrect arguments negative...! >");
            else   {
                obj.deqe.push_back(local);
                obj.V1.push_back(local);
            } 
        }
        obj.size = obj.V1.size();
        std::cout << "Before: " ; 
        printDeque(obj.deqe);
        double start = getTimeOfDay();
        mergeInsertionVector(obj, obj.V1);
        double end = getTimeOfDay();
        obj.vectorTime = end - start;
        start = getTimeOfDay();
        mergeInsertionDeque(obj, obj.deqe);
        end = getTimeOfDay();
        obj.dequeTime =(double) end - start;
        std::cout << "After:  ";
        printDeque(obj.deqe);      
        std::cout << "time to process a range of " << obj.size << " elements with std::vector " << obj.vectorTime / 1000000.0 <<  " us " <<  std::endl;
        std::cout << "time to process a range of " << obj.size << " elements with std::deque " << obj.dequeTime /1000000.0<< " us" <<  std::endl;
    }
}
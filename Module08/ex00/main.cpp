
#include "easyfind.hpp"
#include <vector>
int main(){
    std::vector<int> v ;
    v.push_back(1);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
   if  (easyfind(v, 5) )    
        std::cout << "find index" << std::endl;
    else 
        std::cout << "false we don't fnd index" << std::endl;
    if (easyfind(v, 2))
        std::cout << "find index " << std::endl;
    else    
        std::cout << "false find index" << std::endl;

}
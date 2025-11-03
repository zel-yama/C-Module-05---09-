#include <iostream>
#include <string>

#include "Iter.hpp"
#include <iostream>
#include <string>

void add(int &va){
    va++;

}
void print(const int &av){
    std::cout << av << std::endl;
}
template <typename T> void func(T arg){
    arg--;
} 

int main(){

    int array[] = {3, 3, 3};
    iter<int>(array, 3 , add);
    iter<int, const int>(array, 3, print);
    iter<int, int>(array, 3, func);
    iter<int, const int>(array, 3, print);
}
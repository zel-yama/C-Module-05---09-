

#include "Array.hpp"
int main(){

    int arr[3] = {1, 1, 2};
    Array<int> array(4);
    for(int i = 0; i < 3; i++){
        array.setterIndex(i, arr[i]);
    }
    for(int i = 0; i < 3 ; i++){
        std::cout << array[i] << std::endl;
    }


    

}
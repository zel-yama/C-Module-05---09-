

#include "Serializer.hpp"
#include "Data.h"
int main(){
    Data info;
    info.name = "zakaria";
    info.age = 33;
    uintptr_t var = Serializer::serialize(&info);
    Data *ptr = Serializer::deserialize(var);
    std::cout << "this is age -> " <<  ptr->age << " this is name -> " << ptr->name << std::endl;    

}
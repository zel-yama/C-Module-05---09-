#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "Data.h"
#include <iostream>
class Serializer{

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
 };
#endif

#include "Serializer.hpp"

Serializer::Serializer(){

}

Data *Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}

uintptr_t Serializer::serialize(Data *data){
    return (reinterpret_cast<uintptr_t>(data));
}

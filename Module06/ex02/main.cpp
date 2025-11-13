#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main(){

    Base *obj =  generate();
    identify(obj);
    identify(*obj);  
}

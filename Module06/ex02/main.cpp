#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main(){

    Base *obj =  generate();
    identify(obj);
    identify(*obj);

     Base *obj1 =  generate();
    identify(obj1);
    identify(*obj1);
      Base *obj2 =  generate();
    identify(obj2);
    identify(*obj2);
    Base *obj3 =  generate();
    identify(obj3);
    identify(*obj3);
    Base *obj4 =  generate();
    identify(obj4);
    identify(*obj4);    
}
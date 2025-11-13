
#include "Base.hpp"
#include "B.hpp"
#include "C.hpp"
#include "A.hpp"

Base::~Base(){

}

Base * generate(void){
    std::srand(time(NULL));
    int val = rand() % 3;
    if (val == 0)
        return (new A());
    else if (val == 1)
        return (new B());
    else if (val == 2)
        return (new C());
    return NULL;
}

void identify(Base* p){
    if (dynamic_cast<C*>(p))
        std::cout << "type input is C obj  pointed by" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "type input is B obj pointed by" << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "type input is A obj pointed by " << std::endl;
}


void identify(Base& p){
    try{

        (void)dynamic_cast<A&>(p);
        std::cout << "the type of reference is <A> obj" << std::endl;
    }
    catch(std::exception &e){

    }
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "the type of reference is <C> obj " << std::endl;
    }
    catch(std::exception &e){

    }
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "the type of reference is <B> obj"<< std::endl;
        return ;
    }
    catch(std::exception &e){
        
    }


    return ;
}
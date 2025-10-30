
#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>

template < typename H> void swap(H &num1, H &num2){
    H tmp = num1;
    num1 = num2;
    num2 = tmp;
}
template < typename I> I min(I num1, I num2){
    if (num1 < num2)
        return (num1);
    else if (num1 > num2)
        return (num2);
    return (num2);
}
template <typename I> I max(I num1, I num2){
    if (num1 > num2)
        return (num1);
    else if (num1 < num2)
        return (num2);
    return (num2);
}

#endif

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
template <typename T> bool easyfind( T &container, int tofind){
    for (typename T::iterator i = container.begin(); i != container.end(); i++){
            if (*i == tofind)
                return true;
    }
    return false;

}


#endif
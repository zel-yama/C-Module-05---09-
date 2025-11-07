
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename R> void iter(T *ptr, int const len, void (*func)(R &)){

    if (!ptr || len <= 0)
        return;
    for (int i = 0; i < len; i++){

        func(ptr[i]);
    }


};

#endif
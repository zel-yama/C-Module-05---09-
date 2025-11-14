#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array{

    private:
        T *ptr;
        size_t _len;
    public:
        Array():_len(0){
            ptr = new T[_len];    
        }        
        Array(size_t len):_len(len){
            ptr = new T[_len];
        }
        T &operator=(const Array &obj){
            if (this != &obj){
                this->_len = obj._len;

                delete[] this->ptr;
                this->ptr = new T[_len];
                for(int i = 0; i < _len; i++){
                    ptr[i] = obj.ptr[i];
                }
            }
            return this;
        }
        size_t size()const {
            return _len;
        }
        Array(const Array &obj){
            _len = obj._len;
            ptr = new T[_len];
            for (size_t i = 0; i < _len; i++){
                ptr[i] = obj.ptr[i];
            }
        }
        void setterIndex(unsigned int index, int value){
            if (index >= _len)
                throw  std::invalid_argument("the index out of range ");
            ptr[index] = value;
        }
        T &operator[](unsigned int index){
            if (index >= _len)
                throw  std::invalid_argument("the index out of range ");
            return ptr[index];
        }
        ~Array(){ 
            delete[] ptr;
        }

};

#endif
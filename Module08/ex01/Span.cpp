
#include "Span.hpp"

Span::Span(): size(0), counter(0){
    array = new int[size];
}
Span::~Span(){
    delete [] array;
}
Span &Span::operator=(const Span &obj){

    if (this != &obj){
        delete [] array;
        array = new int[obj.size];
        counter = obj.counter;
        size = obj.size;
        for(unsigned int i = 0; i <  counter; i++ ){
            array[i] = obj.array[i];
        }
    }
    return (*this);
}
Span::Span(const Span &obj){
    size = obj.size;
    counter = obj.counter;
    array = new int[size];
    for(unsigned int i = 0; i < counter; i++){
        array[i] = obj.array[i];
    }
}
Span::Span(unsigned int len):size(len), counter(0){
    array = new int[len];
}

void Span::addNumber(unsigned int value){
  
    if (counter + 1 > size)
        throw std::runtime_error("number of is out of range ");
    else
    {

        array[counter] = value;
        counter++;
    }

}
 int Span::longestSpan()const
{
    if (counter < 2)
        throw std::runtime_error("no Span this instance");
   
    std::vector<int> v ;
    for (unsigned int i = 0; i < counter ; i++){
        v.push_back(array[i]);
    }
    int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());
    return (max - min);

}


int Span::shortestSpan() const {
  
    if (counter < 2 )
        throw std::runtime_error("no Span this instance");
   
    std::vector<int> v ;
    for (unsigned int i = 0; i < counter ; i++){
        v.push_back(array[i]);
    }
    std::sort(v.begin(), v.end());
    std::vector<int>::iterator it = v.begin();
    int first = *(it + 1) - *it;
    while ((it + 1) != v.end())
    {
        int span = *(it +1 ) - *it;
        it++;
        if (first > span)
            first = span;
    }
    return first;
    
}
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    for(std::vector<int>::iterator it = begin; it != end; it++ ){
        addNumber(*it);
    }

}

void Span::displayArray(){
    for (size_t i = 0; i < counter; i++){
        std::cout <<"index -> " << i << " number ->  " << array[i] << std::endl; 
    }
}
 
 
 #include "Span.hpp"
std::vector<int> fillVector(){
    int array[] = {4,5,12,6,9,33,14,20,7};
    std::vector<int> v;
    for(int i = 0; i < 9; i++){
        v.push_back(array[i]);
    }
    return (v);
}
int main()
{
    try{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span spa(9);
        std::vector<int> v = fillVector();
        spa.addNumbers(v.begin(), v.end());
        spa.displayArray();
        std::cout << spa.shortestSpan() << std::endl;
        std::cout << spa.longestSpan() << std::endl;

    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
 
    return 0;
}
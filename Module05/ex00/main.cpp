#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat obj(182, "first");
    }   
    catch (std::exception)
    {
        Bureaucrat obj(10, "sconde");
        obj.decrement_grade(1);
        obj.increment_grade(4);
        std::cout << 
    }
}

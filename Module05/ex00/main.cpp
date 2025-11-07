

#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat obj(182, "ahmd");
    }   
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;

    }
    try
    {
        Bureaucrat obj(10, "jon");
        obj.decrement_grade();
        obj.decrement_grade();
        std::cout << obj << std::endl;
        obj.decrement_grade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;

    }
    try
    {
        Bureaucrat obj;
        obj.increment_grade();
        obj.increment_grade();
        obj.increment_grade();
        
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

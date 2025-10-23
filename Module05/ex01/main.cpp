

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
        obj.decrement_grade(1);
        obj.decrement_grade(4);
        std::cout << obj << std::endl;
        obj.decrement_grade(871);
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;

    }
    try
    {
        Bureaucrat obj;
        obj.increment_grade(3);
        obj.increment_grade(4);
        obj.increment_grade(55);
        
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}

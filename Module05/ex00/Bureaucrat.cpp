
#include "Bureaucrat.hpp"


const char *Bureaucrat::GradeTooHighException::what()const throw()
{
    return "the Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "the Grade is too low";
}

Bureaucrat::Bureaucrat()
{
    this->_Grade = 1;
}

Bureaucrat::Bureaucrat(int val, std::string name) :_name(name)
{
    
    if (val < 1)
        throw Bureaucrat::GradeTooLowException();
    if (val > 150)
        throw Bureaucrat::GradeTooHighException();
    this->_Grade = val;    
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        this->_Grade = obj._Grade;
 
    }   
    return (*this);
}

std::string  Bureaucrat::getter_name() const{
    return(this->_name);
}
int Bureaucrat::getter_grade() const{
    return(this->_Grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj){
    *this = obj;
}
void Bureaucrat::increment_grade(unsigned int val){
         if ( val  >= 150 )
            throw Bureaucrat::GradeTooHighException();
        if ( (val + _Grade) > 150 )
            throw Bureaucrat::GradeTooHighException();
        this->_Grade += val;
}

void Bureaucrat::decrement_grade(int val){
    if (val < -150)
        throw Bureaucrat::GradeTooLowException();
    if (val > 150)
        throw Bureaucrat::GradeTooLowException();
    if ((_Grade - val) <= 0)
        throw Bureaucrat::GradeTooLowException();
    this->_Grade -= val;
}
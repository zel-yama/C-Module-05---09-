
#include "Bureaucrat.hpp"


const char *Bureaucrat::GradeTooHighException::what()const throw()
{
    return " the Grade is too high ";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return " the Grade is too low ";
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
std::ostream &operator<<(std::ostream &out,const Bureaucrat &obj)
{
    out << obj.getter_name() << ", bureaucrat grade " << obj.getter_grade();
    return (out);
}
void Bureaucrat::signForm( Form &obj)
{
    try
    {
        obj.beSigned(*this);
    }
    catch (const std::exception &e) 
    {
        std::cout << obj.getter_name() << " couldn’t sign " << _name << " because ";
        std::cout << e.what() << std::endl;
        return ;
    }
    std::cout << obj.getter_name() << " signed " << _name << std::endl;
    
}
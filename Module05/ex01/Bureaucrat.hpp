
#ifndef BUREAUCRAT_HHP
#define BUREAUCRAT_HHP

#include <iostream>
#include "Form.hpp"
class Form;
class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _Grade;
    public:
        Bureaucrat(int val, const std::string name);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &obj);
        Bureaucrat(const Bureaucrat &obj);
        std::string getter_name() const;
        int getter_grade() const;
        void decrement_grade( int val);
        void increment_grade(unsigned int val);
        void signForm( Form &obj);
        class GradeTooHighException: std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException: std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    };
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);



#endif
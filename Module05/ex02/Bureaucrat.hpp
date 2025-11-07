
#ifndef BUREAUCRAT_HHP
#define BUREAUCRAT_HHP

#include <iostream>
#include "AForm.hpp"

class AForm;
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
        void decrement_grade();
        void increment_grade();
        void signForm( AForm &obj);
        void executeForm(AForm const &form) const;
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    };
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);



#endif
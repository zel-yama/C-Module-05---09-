#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
    
    private:
        const std::string _name;
        bool _is_sing;
        const int _Grade_exc;
        const int _Grade_sing;
    public:
        Form();
        ~Form();
        Form &operator=(const Form &obj);
        Form(const Form &obj);
        Form(const std::string &name, int Grade_exc, int Grade_sing);
        void beSigned( Bureaucrat &obj); 
        std::string getter_name() const;
        bool getter_sing() const;
        int getter_GradeE() const;
        int getter_GradeS() const;
        class GradeTooLowException :public std::exception
        {
            public:
                const char *what() const throw();

        };
        class GradeTooHighException :public std::exception
        {
            public:
                const char *what() const throw();

        };



};
std::ostream &operator<<(std::ostream &out,const Form& obj );

#endif
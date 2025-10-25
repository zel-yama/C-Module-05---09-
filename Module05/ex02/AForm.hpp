#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
    
    private:
        const std::string _name;
        bool _is_sing;
        const int _Grade_exc;
        const int _Grade_sing;
    public:
        AForm();
        ~AForm();
        AForm &operator=(const AForm &obj);
        AForm(const AForm &obj);
        AForm(const std::string &name, int Grade_exc, int Grade_sing);
      
        void beSigned( Bureaucrat &obj);
        virtual void execute(Bureaucrat const & executor) const = 0; 
        std::string getter_name() const;
        bool getter_sing() const;
        int getter_GradeE() const;
        int getter_GradeS() const;
        void BeExecute(const Bureaucrat &obj);
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
std::ostream &operator<<(std::ostream &out,const AForm& obj );

#endif
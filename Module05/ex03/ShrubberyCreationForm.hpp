#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        void execute(const Bureaucrat &executor)const;
        void action_ShrubberyCreationForm(const Bureaucrat &obj) const;
        

};

#endif
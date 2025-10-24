#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>
class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        

};

#endif
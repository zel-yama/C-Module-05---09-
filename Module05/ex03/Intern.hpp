

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern{

    public:
        AForm *makeForm(const std::string &type, const std::string &target);
        Intern();
        ~Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern  &obj);

};

#endif;
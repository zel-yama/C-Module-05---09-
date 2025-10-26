

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    ShrubberyCreationForm form_shrubbery("shrubbery");
    RobotomyRequestForm form_robotomy("robotomy");
    PresidentialPardonForm form_presidential("presidential");
    Bureaucrat bureaucrat(24, "bureaucrat");
    Bureaucrat bureaucrat1(99, "bureaucrat1");
    Bureaucrat bureaucrat2(32, "bureaucrat2");
    bureaucrat1.signForm(form_presidential);
    bureaucrat.signForm(form_shrubbery);
    bureaucrat2.signForm(form_robotomy);
    bureaucrat.signForm(form_presidential);
    bureaucrat1.executeForm(form_robotomy);
    bureaucrat.executeForm(form_presidential);
    bureaucrat2.executeForm(form_robotomy);
    


    return 0;
}



#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main() {

    Intern creator;

    AForm *form_presidential = creator.makeForm("presidential pardon", "target1");
    AForm *form_shrubbery = creator.makeForm("shrubbery creation", "target2");
    AForm *form_robotomy = creator.makeForm("robotomy request", "target3");

    Bureaucrat bureaucrat(24, "bureaucrat");
    Bureaucrat bureaucrat1(99, "bureaucrat1");
    Bureaucrat bureaucrat2(32, "bureaucrat2");
    bureaucrat1.signForm(*form_presidential);
    bureaucrat.signForm(*form_shrubbery);
    bureaucrat2.signForm(*form_robotomy);
    bureaucrat.signForm(*form_presidential);
    bureaucrat1.executeForm(*form_robotomy);
    bureaucrat.executeForm(*form_presidential);
    bureaucrat2.executeForm(*form_robotomy);
    bureaucrat.executeForm(*form_shrubbery);
    
    


    return 0;
}

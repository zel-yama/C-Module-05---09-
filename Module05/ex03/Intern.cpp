

#include "Intern.hpp"

Intern::Intern(){

}
Intern::~Intern(){

}
Intern &Intern::operator=(const Intern &obj){

    (void)obj;
    return (*this);
}

Intern::Intern(const Intern &obj){
    (void)obj;
}
AForm *Intern::create_robtomy(std::string target){
    return new RobotomyRequestForm(target);
}
AForm *Intern::create_presidential(std::string target){
    return new PresidentialPardonForm(target);
}
AForm *Intern::create_shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &type, const std::string &target){

    std::string array[3]= {"shrubbery creation", "robotomy request", "presidential pardon" };
    AForm *(Intern::*functions[])(std::string) = {&Intern::create_shrubbery, &Intern::create_robtomy, &Intern::create_presidential};
    int i = 0 ;
    while (array[i].compare(type) != 0 && i < 3) 
        i++;
    if (3 == i)
    {
        std::cout << "invalid choice !" << std::endl;
        return NULL;
    }
    return ((this->*functions[i])(target));
}

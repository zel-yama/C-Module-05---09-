
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 137,145){

    this->_target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 137,145){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj){

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){

    if (this != &obj){
        AForm::operator=(obj);
    }
    return (*this);
}
void ShrubberyCreationForm::action_ShrubberyCreationForm(const Bureaucrat &obj) const
{

}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{

    if (executor.getter_grade() <= this->getter_GradeE() && this->getter_sing() == true)
        action_ShrubberyCreationForm(executor);
    else   
        throw AForm::GradeTooLowException();
}
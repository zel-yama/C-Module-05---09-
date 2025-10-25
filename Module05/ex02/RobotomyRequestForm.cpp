
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45)
{

}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45){

    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):AForm(obj){

}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){

    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return (*this);

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{

    if (executor.getter_grade() <= this->getter_GradeE() && this->getter_sing() == true)
        //action
    else   
        throw AForm::GradeTooLowException();
}
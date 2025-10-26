
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
void RobotomyRequestForm::action_RobotomyRequestForm(const Bureaucrat &obj) const{
   
    std::cout << "drilling noise" << std::endl;
    (void)obj;
    int ran = rand() % 1000;
    if (ran % 2 == 1)
        std::cout << _target << " has been robotomized successfull " << std::endl;
    else
        std::cout << _target << " that the robotomy failed "<< std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{

    BeExecute(executor);
    action_RobotomyRequestForm(executor);

}
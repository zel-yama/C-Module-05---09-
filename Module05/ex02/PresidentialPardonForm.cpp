


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresindetialPardonForm",5, 25 )
{

}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresindentialPardonForm",5, 25 )
{
    this->_target = target;
}
PresidentialPardonForm::~PresidentialPardonForm(){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):AForm(obj){

}
void PresidentialPardonForm::action_PresidentialPardonForm(const Bureaucrat &obj) const{

    (void)obj;
    std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
void PresidentialPardonForm::execute(const Bureaucrat &executor)const{

    BeExecute(executor);
    action_PresidentialPardonForm(executor);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){

    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return (*this);
}


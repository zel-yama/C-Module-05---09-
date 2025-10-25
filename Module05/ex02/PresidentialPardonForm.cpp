


#include "PresidentialPardonForm.hpp"

PresindetialPardonForm::PresindetialPardonForm():AForm("PresindetialPardonForm",5, 25 )
{

}
PresindetialPardonForm::PresindetialPardonForm(const std::string &target):AForm("PresindetialPardonForm",5, 25 )
{
    this->_target = target;
}
PresindetialPardonForm::~PresindetialPardonForm(){

}

PresindetialPardonForm::PresindetialPardonForm(const PresindetialPardonForm &obj):AForm(obj){

}
void PresindetialPardonForm::execute(const Bureaucrat &executor)const{
    
    if (executor.getter_grade() <= this->getter_GradeE() && this->getter_sing() == true)
        //action
    else   
        throw AForm::GradeTooLowException();
    
}

PresindetialPardonForm &PresindetialPardonForm::operator=(const PresindetialPardonForm &obj){

    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return (*this);
}


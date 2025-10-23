

#include "Form.hpp"


std::string Form::getter_name() const {
    return(this->_name);
}
int Form::getter_GradeE() const{
    return (this->_Grade_exc);
}

int Form::getter_GradeS()const{
    return(this->_Grade_sing);
}
bool Form::getter_sing()const{
    return(this->_is_sing);
}

Form::Form():_is_sing(false), _Grade_exc(1), _Grade_sing(1){

}

Form &Form::operator=(const Form &obj){
    if (this != &obj){
        this->_is_sing = obj._is_sing;
    }
    return (*this);
}
Form::Form(const std::string &name, int Grade_exc, int Grade_sing):_Grade_exc(Grade_exc), _Grade_sing(Grade_sing), _name(name){
    if (Grade_exc > 150 || Grade_sing > 150)
        throw Form::GradeTooHighException();
    if (Grade_exc < 1 || Grade_sing < 1)
        throw Form::GradeTooLowException();
    
}
void Form::beSigned(const Bureaucrat &obj){
    if (obj.getter_grade() > this->_Grade_sing)
        this->_is_sing = true;
}
Form::Form(const Form &obj):_is_sing(false), _Grade_exc(1), _Grade_sing(1) {
    *this = obj;
}

Form::~Form(){

}
const char *Form::GradeTooHighException::what() const throw(){
    return ("the grade is too hight ");

}
const char *Form::GradeTooLowException::what() const throw(){
    return("the grade is too low");
}




#include "AForm.hpp"



std::ostream &operator<<( std::ostream &out,const AForm& obj ){
     out  << "Form name -> " <<  obj.getter_name() << std::endl;
    out << "grade to execute  ->  " <<  obj.getter_GradeE() << std::endl; 
    out << "grade to signed -> "<<  obj.getter_GradeS() << std::endl;
     out  << "signed status -> " ;
     obj.getter_sing()?  out << "true\n" : out << "false\n" ;
    return (out);
}


std::string AForm::getter_name() const {
    return(this->_name);
}
int AForm::getter_GradeE() const{
    return (this->_Grade_exc);
}

int AForm::getter_GradeS()const{
    return(this->_Grade_sing);
}
bool AForm::getter_sing()const{
    return(this->_is_sing);
}

AForm::AForm():_is_sing(false), _Grade_exc(1), _Grade_sing(1){

}

AForm &AForm::operator=(const AForm &obj){
    if (this != &obj){
        this->_is_sing = obj._is_sing;
    }
    return (*this);
}
AForm::AForm(const std::string &name, int Grade_exc, int Grade_sing): _name(name),_Grade_exc(Grade_exc) ,_Grade_sing(Grade_sing){
    if (Grade_exc > 150 || Grade_sing > 150)
        throw AForm::GradeTooLowException();
    if (Grade_exc < 1 || Grade_sing < 1)
        throw AForm::GradeTooHighException();
        
    
}
void AForm::BeExecute(const Bureaucrat &obj)const {

    if (this->_is_sing == false)
        throw FormSigned();
    if (obj.getter_grade() <= this->_Grade_exc)
        return ;
    else
        throw GradeTooLowException();
}
void AForm::beSigned(Bureaucrat &obj){


    if (obj.getter_grade() <= this->_Grade_sing)
        this->_is_sing = true;
    else
        throw GradeTooLowException();
}
AForm::AForm(const AForm &obj):_is_sing(false), _Grade_exc(1), _Grade_sing(1) {
    *this = obj;
}

AForm::~AForm(){

}
const char *AForm::GradeTooHighException::what() const throw(){
    return (" the grade is too hight ");

}
const char *AForm::GradeTooLowException::what() const throw(){
    return(" the grade is too low ");
}

const char *AForm::FileOpenFailed::what() const throw(){
    return ("the file failed to open");
}
const char *AForm::FormSigned::what() const throw(){
    return("the form is not signed ");       
}

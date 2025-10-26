
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
    (void)obj;
    std::string filename = this->_target+"__shrubbery";
   
    std::ofstream file_out(filename.c_str());
    if(!file_out.is_open()){
        throw AForm::FileOpenFailed();
    }
        

	file_out << "      *           *           *           *" << std::endl;
	file_out << "     ***         ***         ***         ***" << std::endl;
	file_out << "    *****       *****       *****       *****" << std::endl;
	file_out << "   *******     *******     *******     *******" << std::endl;
	file_out << "  *********   *********   *********   *********" << std::endl;
	file_out << " *********** *********** *********** ***********" << std::endl;
	file_out << "    |            |            |            |" << std::endl;
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    

    BeExecute(executor);
    action_ShrubberyCreationForm(executor);
}
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
class RobotomyRequestForm: public AForm{

    private:
         std::string _target;
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        void execute(const Bureaucrat &obj)const;
        void action_RobotomyRequestForm(const Bureaucrat &obj) const;

};


#endif
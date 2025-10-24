#ifndef ROBOTOMUYREQUESTFORM_HPP
#define ROBOTOMUYREQUESTFORM_HPP
#include "AForm.hpp"
#include <iostream>
class RobotomyRequestForm: public AForm{

    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        RobotomyRequestForm(const RobotomyRequestForm &obj);

};


#endif
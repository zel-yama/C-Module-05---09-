#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm: public AForm{
    
        private:
            std::string _target;
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
         void execute(Bureaucrat const & executor)const;
        void action_PresidentialPardonForm(const Bureaucrat &obj) const;
        
};



#endif

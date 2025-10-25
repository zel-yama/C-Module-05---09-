#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class PresindetialPardonForm: public AForm{
    
        private:
            std::string _target;
    public:
        PresindetialPardonForm(const std::string &target);
        PresindetialPardonForm();
        ~PresindetialPardonForm();
        PresindetialPardonForm &operator=(const PresindetialPardonForm &obj);
        PresindetialPardonForm(const PresindetialPardonForm &obj);
         void execute(Bureaucrat const & executor)const;
        
};



#endif
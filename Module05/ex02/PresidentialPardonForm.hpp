#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresindetialPardonForm: public AForm{
    public:
        PresindetialPardonForm();
        ~PresindetialPardonForm();
        PresindetialPardonForm &operator=(const PresindetialPardonForm &obj);
        PresindetialPardonForm(const PresindetialPardonForm &obj);
        
};



#endif
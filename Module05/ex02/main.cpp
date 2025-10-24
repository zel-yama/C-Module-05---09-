

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    Bureaucrat person(20, "alic");

    Form contra("contarct", 42, 30);
    Form contra1("contract1", 15, 19);
    person.signForm(contra);
    person.signForm(contra1);

}

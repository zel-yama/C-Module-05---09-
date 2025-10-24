

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    std::cout << "\n=== TEST 3: Successful signing ===" << std::endl;
    Bureaucrat john( 40, "John");
    Form contract("Contract", 50, 25);

    std::cout << contract << std::endl;
    john.signForm(contract);
    std::cout << contract << std::endl;
}

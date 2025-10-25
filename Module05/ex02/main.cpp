

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== TEST 1: Successful signing and executing ===" << std::endl;
    try {
        Bureaucrat boss(1, "Alice");
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Robo");
        PresidentialPardonForm pardon("Zaphod");

        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Bureaucrat too low to sign ===" << std::endl;
    try {
        Bureaucrat low(150, "LowGrade");
        RobotomyRequestForm form("Target");
        low.signForm(form); // should fail
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Bureaucrat too low to execute ===" << std::endl;
    try {
        Bureaucrat signer(20, "Signer");
        Bureaucrat executor(26, "Executor");
        PresidentialPardonForm form("Zaphod");

        signer.signForm(form);
        executor.executeForm(form); // should fail
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Execute unsigned form ===" << std::endl;
    try {
        Bureaucrat boss(1, "Boss");
        ShrubberyCreationForm form("office");
        boss.executeForm(form); // not signed
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Random robotomy attempts ===" << std::endl;
    try {
        Bureaucrat top(1, "Top");
        RobotomyRequestForm robot("Unit-42");

        top.signForm(robot);
        for (int i = 0; i < 5; i++)
            top.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

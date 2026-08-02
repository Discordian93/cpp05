#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat starmer("Starmer", 150);
    Bureaucrat burnham("Burnham", 1);

    std::cout << starmer << " " << burnham << std::endl;

    Form contract("Top Secret", 75, 50);
    std::cout << contract << std::endl;

    try
    {
        contract.beSigned(starmer);
        std::cout << starmer.getName() << " signed the form." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << starmer.getName() << " couldn't sign: " << e.what() << std::endl;
    }

    try
    {
        //contract.beSigned(burnham);
        burnham.signForm(contract);
        std::cout << burnham.getName() << " signed the form." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << burnham.getName() << " couldn't sign: " << e.what() << std::endl;
    }

    std::cout << contract << std::endl;

    Form copy = contract;
    std::cout << "Copy: " << copy << std::endl;

    return 0;
}

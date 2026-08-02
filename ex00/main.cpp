#include "Bureaucrat.hpp"
int main(void)
{
    Bureaucrat starmer = Bureaucrat("Starmer", 150);
    Bureaucrat burnham = Bureaucrat("Burnham", 1);
    std::cout << starmer << " " << burnham << std::endl;
    try
    {
        std::cout << starmer << " " << burnham << std::endl;
        starmer.decreaseGrade();
    }
    catch(const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    try
    {
        burnham.increaseGrade();
    }
    catch(const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << starmer << " " << burnham << std::endl;
}

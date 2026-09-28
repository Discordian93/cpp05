#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "===== Bureaucrat construction =====" << std::endl;
    try
    {
        Bureaucrat invalid("Nobody", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat invalid("Nobody", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    Bureaucrat president("Beeblebrox", 1);
    Bureaucrat clerk("Bartleby", 140);
    std::cout << president << std::endl;
    std::cout << clerk << std::endl;

    std::cout << std::endl << "===== Form construction =====" << std::endl;
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << std::endl << "===== Executing an unsigned form =====" << std::endl;
    president.executeForm(shrubbery);

    std::cout << std::endl << "===== Signing =====" << std::endl;
    clerk.signForm(shrubbery);   // 140 <= 145, succeeds
    clerk.signForm(robotomy);    // 140 > 72, fails
    president.signForm(robotomy);
    president.signForm(pardon);

    std::cout << std::endl << "===== Executing with an insufficient grade =====" << std::endl;
    clerk.executeForm(shrubbery); // 140 > 137, fails

    std::cout << std::endl << "===== Executing successfully =====" << std::endl;
    president.executeForm(shrubbery);
    president.executeForm(robotomy);
    president.executeForm(pardon);

    std::cout << std::endl << "===== Robotomy is random =====" << std::endl;
    for (int i = 0; i < 5; i++)
        president.executeForm(robotomy);

    std::cout << std::endl << "===== Can sign but not execute =====" << std::endl;
    Bureaucrat middle("Middle", 50);
    RobotomyRequestForm robotomy2("R2-D2");
    middle.signForm(robotomy2);    // 50 <= 72, succeeds
    middle.executeForm(robotomy2); // 50 > 45, fails

    std::cout << std::endl << "===== Exactly on the required grade =====" << std::endl;
    Bureaucrat exact("Exact", 45);
    exact.executeForm(robotomy2);  // 45 <= 45, succeeds

    std::cout << std::endl << "===== Action fails: file cannot be created =====" << std::endl;
    ShrubberyCreationForm badShrubbery("no_such_dir/home");
    president.signForm(badShrubbery);
    president.executeForm(badShrubbery);

    std::cout << std::endl << "===== Copy constructor and assignment =====" << std::endl;
    PresidentialPardonForm copied(pardon); // pardon was signed earlier
    std::cout << "copy:     " << copied << ", target: " << copied.getTarget() << std::endl;

    PresidentialPardonForm assigned("Trillian");
    std::cout << "before =: " << assigned << ", target: " << assigned.getTarget() << std::endl;
    assigned = pardon;
    std::cout << "after =:  " << assigned << ", target: " << assigned.getTarget() << std::endl;

    std::cout << std::endl << "===== Polymorphism through a base pointer =====" << std::endl;
    AForm* forms[3];
    forms[0] = new ShrubberyCreationForm("garden");
    forms[1] = new RobotomyRequestForm("Marvin");
    forms[2] = new PresidentialPardonForm("Arthur Dent");

    for (int i = 0; i < 3; i++)
    {
        president.signForm(*forms[i]);
        president.executeForm(*forms[i]);
        delete forms[i];
    }

    std::cout << std::endl << "===== Grade increment / decrement =====" << std::endl;
    Bureaucrat top("Top", 1);
    Bureaucrat bottom("Bottom", 150);
    try
    {
        top.increaseGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    try
    {
        bottom.decreaseGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    bottom.increaseGrade();
    std::cout << bottom << std::endl;

    std::cout << std::endl << "===== Intern: making existing forms =====" << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

    std::cout << *rrf << std::endl;
    std::cout << *scf << std::endl;
    std::cout << *ppf << std::endl;

    president.signForm(*ppf);
    president.executeForm(*ppf);

    delete rrf;
    delete scf;
    delete ppf;

    std::cout << std::endl << "===== Intern: making a nonexistent form =====" << std::endl;
    try
    {
        AForm* bad = someRandomIntern.makeForm("coffee machine", "Espresso");
        delete bad; // never reached
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== Intern: copy =====" << std::endl;
    Intern otherIntern(someRandomIntern);
    AForm* fromCopy = otherIntern.makeForm("presidential pardon", "Trillian");
    delete fromCopy;

    return (0);
}
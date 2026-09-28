#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Requested form does not exist");
}

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePardon(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormMaker makers[3] = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*(makers[i]))(target));
        }
    }

    std::cerr << "Intern couldn't create " << formName
              << " because this form does not exist." << std::endl;
    throw FormNotFoundException();
}

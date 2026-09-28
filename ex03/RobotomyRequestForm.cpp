#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

// Succeeds 50% of the time. srand() is seeded once in main, not here:
// reseeding on every call would make consecutive results identical.
void RobotomyRequestForm::executeAction(const Bureaucrat& executor) const
{
    (void)executor;

    std::cout << "* BZZZZZZT ... DRRRRRRR ... VRRRRRRRM *" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed" << std::endl;
}

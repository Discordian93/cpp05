#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade too high, maximum grade: 1");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade too low, maximum grade: 150");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

AForm::AForm() : _name("Default Form"), _signed(false), _requiredSignGrade(150), _requiredExecuteGrade(150)
{
}

AForm::AForm(std::string name, int requiredSignGrade, int requiredExecuteGrade)
    : _name(name), _signed(false), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade)
{
    if (requiredSignGrade < 1 || requiredExecuteGrade < 1)
    {
        throw GradeTooHighException();
    }
    if (requiredSignGrade > 150 || requiredExecuteGrade > 150)
    {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _requiredSignGrade(other._requiredSignGrade), _requiredExecuteGrade(other._requiredExecuteGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getSigned() const
{
    return (_signed);
}

int AForm::getRequiredSignGrade() const
{
    return (_requiredSignGrade);
}

int AForm::getRequiredExecuteGrade() const
{
    return (_requiredExecuteGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _requiredSignGrade)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > _requiredExecuteGrade)
        throw GradeTooLowException();
    if (!_signed)
        throw FormNotSignedException();
    executeAction(executor);
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no")
       << ", sign grade: " << f.getRequiredSignGrade()
       << ", execute grade: " << f.getRequiredExecuteGrade();
    return os;
}


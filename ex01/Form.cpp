#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high, maximum grade: 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low, maximum grade: 150");
}

Form::Form() : _name("Default Form"), _signed(false), _requiredSignGrade(150), _requiredExecuteGrade(150)
{
}

Form::Form(std::string name, int requiredSignGrade, int requiredExecuteGrade)
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

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), _requiredSignGrade(other._requiredSignGrade), _requiredExecuteGrade(other._requiredExecuteGrade)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

Form::~Form()
{
}

const std::string Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getRequiredSignGrade() const
{
    return (_requiredSignGrade);
}

int Form::getRequiredExecuteGrade() const
{
    return (_requiredExecuteGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _requiredSignGrade)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no")
       << ", sign grade: " << f.getRequiredSignGrade()
       << ", execute grade: " << f.getRequiredExecuteGrade();
    return os;
}


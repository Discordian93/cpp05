#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high, maximum grade: 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low, maximum grade: 150");
}

Bureaucrat::Bureaucrat() : _name("John Smith"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::increaseGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}



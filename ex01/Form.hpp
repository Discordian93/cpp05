#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Form
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _requiredSignGrade;
        const int         _requiredExecuteGrade;

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Form();
        Form(std::string name, int requiredSignGrade, int requiredExecuteGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string getName() const;
        bool getSigned() const;
        int getRequiredSignGrade() const;
        int getRequiredExecuteGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <iostream>

class AForm
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _requiredSignGrade;
        const int         _requiredExecuteGrade;

    protected:
        virtual void executeAction(const Bureaucrat& executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        AForm();
        AForm(std::string name, int requiredSignGrade, int requiredExecuteGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string getName() const;
        bool getSigned() const;
        int getRequiredSignGrade() const;
        int getRequiredExecuteGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif

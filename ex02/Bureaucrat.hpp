#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;

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

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void increaseGrade();
        void decreaseGrade();
        void signForm(AForm& form);
        void executeForm(AForm& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif

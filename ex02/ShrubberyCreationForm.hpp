#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;

    protected:
        virtual void executeAction(const Bureaucrat& executor) const;

    class FileOpenException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        const std::string getTarget() const;
};

#endif
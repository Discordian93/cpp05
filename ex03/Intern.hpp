#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
#include <exception>
#include <iostream>

class Intern
{
    private:
        typedef AForm* (Intern::*FormMaker)(const std::string& target);

        AForm* makeShrubbery(const std::string& target);
        AForm* makeRobotomy(const std::string& target);
        AForm* makePardon(const std::string& target);

    public:
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif

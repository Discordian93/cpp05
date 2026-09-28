#include "ShrubberyCreationForm.hpp"
#include <fstream>

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return ("could not open file");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void ShrubberyCreationForm::executeAction(const Bureaucrat& executor) const
{
    (void)executor;
    std::ofstream outfile((_target + "_shrubbery").c_str());

    if (!outfile.is_open())
        throw FileOpenException();

    outfile << "       ###\n"
            << "      #####\n"
            << "     #######\n"
            << "    #########\n"
            << "   ###########\n"
            << "        |\n"
            << "        |\n"
            << "\n"
            << "         #\n"
            << "        ###\n"
            << "       #####\n"
            << "      #######\n"
            << "     #########\n"
            << "    ###########\n"
            << "         |\n"
            << "         |\n";

    outfile.close();
}
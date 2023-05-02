/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 13:58:50 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 13:44:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileNoPerm::what() const throw() {
	return ("File permission error");
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	if (this == &src)
		return (*this);
	this->Form::operator=(src);
	this->_target = src._target;
	return (*this);
}

void ShrubberyCreationForm::treeCreate(void) const {
	std::ofstream outfile (this->_target + "_shrubbery");
	if (outfile.fail()) {
		throw ShrubberyCreationForm::FileNoPerm();
		return ;
	}

	outfile << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\ _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\" << std::endl;
	outfile << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\ _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\" << std::endl;
	outfile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignStatus()) {
		throw ShrubberyCreationForm::FormNotSigned();
	}
	if (executor.getGrade() <= this->getExecGrade()) {
		ShrubberyCreationForm::treeCreate();
	}
	else {
		throw ShrubberyCreationForm::GradeTooLowException();
	}
}

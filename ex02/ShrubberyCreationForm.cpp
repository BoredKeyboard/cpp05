/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 13:58:50 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/01 15:45:39 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCretionForm", 145, 137), _target("") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCretionForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	if (this == &src)
		return (*this);
	this->AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

void ShrubberyCreationForm::treeCreate(void) {
	std::ofstream outfile (this->_target + "_shrubbery");
	if (outfile.fail()) {
		std::cout << "File creation error" << std::endl;
		return ;
	}

	outfile << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\ _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\" << std::endl;
	outfile << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\ _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\" << std::endl;
	outfile.close();
}

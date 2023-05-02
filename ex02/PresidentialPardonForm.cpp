/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 14:32:28 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 13:44:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("") {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form("PresidentialPardonForm", 25, 5), _target(target) {
	// std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	if (this == &src)
		return (*this);
	this->Form::operator=(src);
	this->_target = src._target;
	return (*this);
}

void PresidentialPardonForm::Pardon(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignStatus()) {
		throw PresidentialPardonForm::FormNotSigned();
	}
	if (executor.getGrade() <= this->getExecGrade()) {
		PresidentialPardonForm::Pardon();
	}
	else {
		throw PresidentialPardonForm::GradeTooLowException();
	}
}

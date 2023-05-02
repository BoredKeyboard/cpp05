/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 14:32:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 13:44:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("") {
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	if (this == &src)
		return (*this);
	this->Form::operator=(src);
	this->_target = src._target;
	return (*this);
}

void RobotomyRequestForm::Robotomize(void) const {
	std::cout << "**Drilling noises**" << std::endl;
	if (rand() & 2) {
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	}
	else {
		std::cout << "Robotomy failed" << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignStatus()) {
		throw RobotomyRequestForm::FormNotSigned();
	}
	if (executor.getGrade() <= this->getExecGrade()) {
		RobotomyRequestForm::Robotomize();
	}
	else {
		throw RobotomyRequestForm::GradeTooLowException();
	}
}

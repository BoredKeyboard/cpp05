/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 13:12:24 by mforstho      #+#    #+#                 */
/*   Updated: 2023/04/25 14:02:31 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

AForm::AForm(void) : _name(""), _is_signed(false), _sign_grade(1), _exec_grade(1) {
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name), _is_signed(src._is_signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm(void) {
	std::cout << "AForm destructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & src) {
	if (this == &src)
		return (*this);
	this->_is_signed = src._is_signed;
	const_cast<std::string&>(this->_name) = src._name;
	const_cast<int&>(this->_sign_grade) = src._sign_grade;
	const_cast<int&>(this->_exec_grade) = src._exec_grade;
	return (*this);
}

std::string	AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSignStatus(void) const {
	return (this->_is_signed);
}

int 	AForm::getSignGrade(void) const {
	return (this->_sign_grade);
}

int 	AForm::getExecGrade(void) const {
	return (this->_exec_grade);
}

void	AForm::beSigned(Bureaucrat const & src) {
	if (src.getGrade() <= this->getSignGrade()) {
		this->_is_signed = true;
	}
	else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, AForm &src) {
	os << src.getName() << ", Aform sign grade " << src.getSignGrade() << ", Aform execute grade " << src.getExecGrade() << ", Aform signed status: " << src.getSignStatus() << std::endl;
	return (os);
}

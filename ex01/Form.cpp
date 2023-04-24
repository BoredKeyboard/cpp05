/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 13:12:24 by mforstho      #+#    #+#                 */
/*   Updated: 2023/04/24 16:19:10 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

Form::Form(void) : _name(""), _is_signed(false), _sign_grade(1), _exec_grade(1) {
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _is_signed(src._is_signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(Form const & src) {
	if (this == &src)
		return (*this);
	this->_is_signed = src._is_signed;
	const_cast<std::string&>(this->_name) = src._name;
	const_cast<int&>(this->_sign_grade) = src._sign_grade;
	const_cast<int&>(this->_exec_grade) = src._exec_grade;
	return (*this);
}

std::string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSignStatus(void) const {
	return (this->_is_signed);
}

int 	Form::getSignGrade(void) const {
	return (this->_sign_grade);
}

int 	Form::getExecGrade(void) const {
	return (this->_exec_grade);
}

void	Form::beSigned(Bureaucrat const & src) {
	if (src.getGrade() <= this->getSignGrade()) {
		this->_is_signed = true;
	}
	else {
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, Form &src) {
	os << src.getName() << ", form sign grade " << src.getSignGrade() << ", form execute grade " << src.getExecGrade() << ", form signed status: " << src.getSignStatus() << std::endl;
	return (os);
}

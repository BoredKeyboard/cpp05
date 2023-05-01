/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 15:01:17 by mforstho      #+#    #+#                 */
/*   Updated: 2023/04/25 14:03:13 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

Bureaucrat::Bureaucrat(void) : _name(""), _grade(1) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}

}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
	const_cast<std::string&>(this->_name) = src._name;
	return (*this);
}

std::string const & Bureaucrat::getName(void) {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::incrGrade(int amount) {
	if (this->_grade - amount < 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->_grade -= amount;
}

void Bureaucrat::decrGrade(int amount) {
	if (this->_grade + amount > 150) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade += amount;
}

void Bureaucrat::signForm(AForm & form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException & ex) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because their grade is too low" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &src) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

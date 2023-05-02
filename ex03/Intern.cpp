/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 13:35:42 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 18:02:23 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(Intern const & src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor caled" << std::endl;
}

Intern & Intern::operator=(Intern const & src) {
	if (this == &src)
		return (*this);
	return (*this);
}

Form * newShrubbery(std::string target) {
	Form *shrubbery = new ShrubberyCreationForm(target);
	return (shrubbery);
}

Form * newRobotomy(std::string target) {
	Form *robotomy = new RobotomyRequestForm(target);
	return (robotomy);
}

Form * newPardon(std::string target) {
	Form *pardon = new PresidentialPardonForm(target);
	return (pardon);
}

Form * Intern::makeForm(std::string formName, std::string target) {
	std::string name_arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	Form *(* arr[])(std::string) = {&newShrubbery, &newRobotomy, &newPardon};
	Form *newform;
	for (int i = 0; i < 3; i++) {
		if (formName == name_arr[i]) {
			newform = arr[i](target);
			std::cout << "Intern creates a new " << formName << " form!" << std::endl;
			return (newform);
		}
	}
	std::cout << "No form of type " << formName << " exists" << std::endl;
	return (NULL);
}

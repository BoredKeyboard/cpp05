/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:06:21 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/03 14:48:15 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Shrubbery : sign 145, exec 137
// Robotomy	 : sign 72, exec 45
// pardon	 : sign 25, exec 5

void leakfunc(void) {
	system("leaks -q crat");
}

int	main(void) {
	atexit(leakfunc);
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat	b("Ang", 47);
		b.executeForm(*rrf);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		b.incrGrade(2);
		b.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		PresidentialPardonForm	f("Esker");
		Bureaucrat	b("Feldspar", 26);

		b.signForm(f);
		b.incrGrade(1);
		b.signForm(f);

		b.executeForm(f);
		b.incrGrade(20);
		b.executeForm(f);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotom request", "Bender");

		Bureaucrat	b("Ang", 47);
		b.executeForm(*rrf);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		b.incrGrade(2);
		b.executeForm(*rrf);
		delete rrf;
	}
	return (EXIT_SUCCESS);
}

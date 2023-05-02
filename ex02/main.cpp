/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:06:21 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 13:44:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Shrubbery : sign 145, exec 137
// Robotomy	 : sign 72, exec 45
// pardon	 : sign 25, exec 5

int	main(void) {
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
		ShrubberyCreationForm	f("treecreate");
		Bureaucrat	b("Bab", 137);

		b.signForm(f);
		b.executeForm(f);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		RobotomyRequestForm	f("Chert");
		Bureaucrat	b("Riebeck", 45);

		b.signForm(f);
		b.executeForm(f);
	}
	return (EXIT_SUCCESS);
}

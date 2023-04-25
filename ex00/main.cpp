/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:06:21 by mforstho      #+#    #+#                 */
/*   Updated: 2023/04/25 12:02:05 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	{
		Bureaucrat	b1("Bob", 74);

		std::cout << b1;
		std::cout << "Increment by 5" << std::endl;
		b1.incrGrade(5);
		std::cout << b1;
		std::cout << "Decrement by 10" << std::endl;
		b1.decrGrade(10);
		std::cout << b1;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat b2("Tom", 3);

		std::cout << b2;
		std::cout << "Increment Tom by 2" << std::endl;
		b2.incrGrade(2);
		std::cout << b2;
		std::cout << "Increment Tom by 1" << std::endl;
		try {
			b2.incrGrade(1);
		}
		catch (Bureaucrat::GradeTooHighException test) {
			std::cout << "Grade too high" << std::endl;
		}
		std::cout << b2;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat b3("Eve", 148);

		std::cout << b3;
		std::cout << "Decrement Eve by 2" << std::endl;
		b3.decrGrade(2);
		std::cout << b3;
		std::cout << "Decrement Eve by 1" << std::endl;
		try {
			b3.decrGrade(1);
		}
		catch (Bureaucrat::GradeTooLowException test) {
			std::cout << "Grade too low" << std::endl;
		}
		std::cout << b3;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try {
			Bureaucrat b4("Alex", 151);
		}
		catch (Bureaucrat::GradeTooLowException test) {
			std::cout << "Grade too low" << std::endl;
		}
		try {
			Bureaucrat b5("Max", 0);
		}
		catch (Bureaucrat::GradeTooHighException test) {
			std::cout << "Grade too high" << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}

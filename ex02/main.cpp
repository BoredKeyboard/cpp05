/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:06:21 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/01 12:35:46 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	// {
	// 	AForm		f1("testform", 42, 21);
	// 	Bureaucrat	b1("Bob", 43);

	// 	b1.signForm(f1);
	// 	b1.incrGrade(1);
	// 	b1.signForm(f1);
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;
	// {
	// 	AForm		f2("form2", 5, 1);
	// 	Bureaucrat	b2("Bab", 7);

	// 	try {
	// 		f2.beSigned(b2);
	// 	}
	// 	catch (AForm::GradeTooLowException & ex) {
	// 		std::cout << ex.what() << std::endl;
	// 	}
	// }
	std::cout << std::endl;
	std::cout << std::endl;
	{
		ShrubberyCreationForm	f2("test");
		Bureaucrat	b2("Bab", 7);

		f2.treeCreate();
	}
	return (EXIT_SUCCESS);
}

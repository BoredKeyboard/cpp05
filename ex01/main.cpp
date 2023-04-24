/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:06:21 by mforstho      #+#    #+#                 */
/*   Updated: 2023/04/24 16:21:19 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	{
		Form		f1("testform", 42, 21);
		Bureaucrat	b1("Bob", 43);

		b1.signForm(f1);
		b1.incrGrade(1);
		b1.signForm(f1);
	}
}

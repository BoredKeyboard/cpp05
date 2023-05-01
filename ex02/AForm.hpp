/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 13:12:22 by mforstho      #+#    #+#                 */
/*   Updated: 2023/04/25 14:09:51 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_sign_grade;
		int	const			_exec_grade;
	public:
		AForm(void);
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm const & src);
		virtual ~AForm(void);
		AForm & operator=(AForm const & src);
		void	beSigned(Bureaucrat const & src);
		std::string	getName(void) const;
		bool	getSignStatus(void) const;
		int 	getSignGrade(void) const;
		int 	getExecGrade(void) const;

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm &src);

#endif

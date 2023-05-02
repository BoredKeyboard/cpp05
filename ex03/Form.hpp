/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 13:46:41 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 13:46:42 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_sign_grade;
		int	const			_exec_grade;
	public:
		Form(void);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const & src);
		virtual ~Form(void);
		Form & operator=(Form const & src);
		void	beSigned(Bureaucrat const & src);
		std::string	getName(void) const;
		bool	getSignStatus(void) const;
		int 	getSignGrade(void) const;
		int 	getExecGrade(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
		class FormNotSigned : public std::exception {
			public:
				const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form &src);

#endif

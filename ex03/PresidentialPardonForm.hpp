/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 14:32:25 by mforstho      #+#    #+#                 */
/*   Updated: 2023/05/02 13:44:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string	_target;
		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
		void Pardon(void) const;
		void execute(Bureaucrat const & executor) const;
};

#endif

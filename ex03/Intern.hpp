/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:22:54 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 16:24:17 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
	private:

		Form* makeppf( std::string const target );
		Form* makerrf( std::string const target );
		Form* makescf( std::string const target );

	public:

		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& boj);

		class FormNotFoundException : public std::exception{
			public:
				const char* what() const throw(){
					return "This type of form does not exist.";
				}
		};

		Form* makeForm( std::string form, const std::string target );
		typedef Form* (Intern::*getFunc)( const std::string );
};

#endif
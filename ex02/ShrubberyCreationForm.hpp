/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:28:46 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 14:17:30 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include	"Form.hpp"
#include	<fstream>

class Bureaucrat;

class	ShrubberyCreationForm : public Form
{

		std::string _target;
		
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string _target );
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& boj);

		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

#endif
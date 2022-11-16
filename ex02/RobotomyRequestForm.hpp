/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:09:46 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 14:55:12 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class Bureaucrat;

class	RobotomyRequestForm : public Form
{

		std::string _target;
		
	public:

		RobotomyRequestForm();
		RobotomyRequestForm( const std::string _target );
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& boj);

		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

#endif
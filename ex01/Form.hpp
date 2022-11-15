/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:02:45 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/15 20:53:54 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
		const std::string _name;
		bool _signed;
		const int _reqsign;
		const int _reqexec;

	public:
		
		Form(const std::string name, const int sign, const int exec);
		Form();
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &src);

		class GradeHigh: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Jamaican Grade");	
				}
		};

		class GradeLow: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Low Grade, yo!");
				}
		};

		void beSigned( const Bureaucrat& obj );
		const std::string getName(void) const;
		bool getIfSigned() const;
		int getReqSign() const;
		int getReqExec() const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);


#endif

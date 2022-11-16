/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:02:45 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 15:20:21 by vsimeono         ###   ########.fr       */
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

		class FormNotSigned: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Form not Signed");
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

		virtual void beSigned( const Bureaucrat& obj );
		virtual const std::string getName(void) const;
		virtual bool getIfSigned() const;
		virtual int getReqSign() const;
		virtual int getReqExec() const;
		virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Form &src);


#endif

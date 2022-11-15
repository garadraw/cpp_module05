/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:59:49 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/15 20:56:51 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include "Form.hpp"

class Form;

class Bureaucrat
{
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

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

		const std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(const Form & src);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif


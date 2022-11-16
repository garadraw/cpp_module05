/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:59:31 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 13:39:19 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeLow();
	else if (grade < 1)
		throw Bureaucrat::GradeHigh();
	this->_grade = grade;
	std::cout << "Bureaucrat" << _name << " was Created " << std::endl; 
}

Bureaucrat::Bureaucrat(): _name("MediumBiro"), _grade(150)
{
	std::cout << "Medium Bureaucrat was Created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called" << std::endl; 
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name("Probably Medium Biro")
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	this->_grade = src._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Overload = Function Called" << std::endl;
	this->_grade = src._grade;
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::increment(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeHigh();
		this->_grade -= 1;
	}
	catch (Bureaucrat::GradeLow &e)
	{
		std::cout << e.what() << std::endl;
		this->_grade = 1;
	}
}

void Bureaucrat::decrement(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeLow();
		this->_grade += 1;
	}
	catch (Bureaucrat::GradeLow &e)
	{
		std::cout << e.what() << std::endl;
		this->_grade = 150;
	}
}


void Bureaucrat::signForm(const Form &src)
{
	if (src.getIfSigned() == true)
		std::cout << this->getName() << " is already Signed" << src.getName() << std::endl;
	else
		std::cout << this->getName() << " can not Sign " << src.getName() << std::endl;
}

void Bureaucrat::executeForm(const Form &src)
{
	try
	{
		src.execute(*this);
		std::cout << this->getName() << " executed " << src.getName() << std::endl;
	}
	catch(Form::FormNotSigned &e)
	{
		std::cout << e.what() << " Form not Signed " << std::endl;
	}
	catch (Form::GradeLow &e)
	{
		std::cout << "Grade too Low" << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	return (os << src.getName() + " has a Grade of " << src.getGrade() << std::endl);
}



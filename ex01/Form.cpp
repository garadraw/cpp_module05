/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:02:29 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/15 20:55:19 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int sign, const int exec):
	_name(name), _signed(false), _reqsign(sign), _reqexec(exec)	
{
	if (this->_reqsign < 1 || this->_reqexec < 1)
		throw Form::GradeHigh();
	if (this->_reqsign > 150 || this->_reqexec > 150)
		throw Form::GradeLow();
	std::cout << "Form Constructor Called and Initilised Values" << std::endl;
}

Form::Form():
	_name("Yellow Form"), _signed(false), _reqsign(75), _reqexec(75)
{
	std::cout << "Yellow Form Created" << std::endl; 
}

Form::~Form()
{
	std::cout << "Form Deconstructor Called" << std::endl;
}

Form::Form(const Form &src): _name(src._name), _reqsign(src._reqsign), _reqexec(src._reqexec)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
	this->_signed = src._signed;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Overloader = Function Called" << std::endl;
	this->_signed = src._signed;
	return (*this);
}


const std::string Form::getName() const{
	return this->_name;
}

bool Form::getIfSigned() const{
	return this->_signed;
}

int Form::getReqExec() const{
	return this->_reqexec;
}

int Form::getReqSign() const{
	return this->_reqsign;
}

void Form::beSigned(const Bureaucrat &src)
{
	try
	{
		if (src.getGrade() > this->getReqSign())
			throw Form::GradeLow();
		this->_signed = true;
	}
	catch (Form::GradeLow &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	std::string sign;
	if (src.getIfSigned() == true)
		sign = "signed";
	else 
		sign = "not signed";
	return (os << "Form" << src.getName() << ", Status:" << sign << std::endl << "Necessary Min Grade to Sign" << src.getReqSign()  << "Necessary Min Grade to Exec" << src.getReqExec() << std::endl);
}

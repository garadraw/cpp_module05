/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:09:37 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 14:45:41 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const  std::string target):
	Form("Presidential Pardon Form", 25, 5), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5), _target("Pardonne")
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstrucotr Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(), _target(src._target)
{
	std::cout << "PresidentialPardonForm  Copy Constructor Called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm Overloader = Function Called" << std::endl;
	this->_target = src.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat & execute) const
{
	if (this->getIfSigned() == false)
		throw Form::FormNotSigned();
	if (this->getReqExec() < execute.getGrade())
		throw Form::GradeLow();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
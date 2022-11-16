/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:09:43 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 14:46:11 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : 
	Form("Robotomy Request Form", 72, 42), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(): 
	Form("Robotomy Request Form", 72, 42), _target("Cici"){
		
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm Deconstructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(), _target(obj._target){
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	std::cout << "RobotomyRequestForm Overloader = Function Called" << std::endl;
	this->_target = obj.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &execute) const {
	if (this->getIfSigned() == false)
		throw Form::FormNotSigned();
	if (this->getReqExec() < execute.getGrade())
		throw Form::GradeLow();
	std::cout << "BRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	srand(time(NULL));
	if ((rand() % 2) == 0)
		std::cout << "Robotomy failed" << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
}
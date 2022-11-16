/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:32 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 16:24:51 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern(){
	std::cout << "Intern appeared" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern burned" << std::endl;
}

Intern::Intern(const Intern& obj){
	std::cout << "Intern class copy constructor" << std::endl;
	*this = obj;
}

Form* Intern::makeppf( std::string const target ){
	Form* form = new PresidentialPardonForm(target);
	return form;
}

Form* Intern::makerrf( std::string const target ){
	Form* form = new RobotomyRequestForm(target);
	return form;
}

Form* Intern::makescf( std::string const target ){
	Form* form = new ShrubberyCreationForm(target);
	return form;
}

Form* Intern::makeForm( std::string form, std::string target ){
	getFunc f[3] = { &Intern::makeppf, &Intern::makerrf, &Intern::makescf};
	std::string l[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	bool check = 0;
	try{
		for(int i = 0; i < 3; i++){
			if (form == l[i]){
				return (this->*f[i])(target);
			}
		}
		if (!check)
			throw Intern::FormNotFoundException();
	}
	catch(Intern::FormNotFoundException & e){
		std::cout << "Exception cought " << e.what() << std::endl;
	}
	return nullptr;
}

Intern& Intern::operator=(const Intern& obj){
	std::cout << "Intern class copy asignment" << std::endl;
	(void) obj;
	return *this;
}
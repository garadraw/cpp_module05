/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:59:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 15:17:05 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << " Testing "<< std::endl;
	try{
		Bureaucrat a("James", 1);
		std::cout << a;
		PresidentialPardonForm f;
		std::cout << f;
		
		std::cout << std::endl;

		f.beSigned(a);
		std::cout << f;
		a.executeForm(f);
		std::cout << std::endl;
	}
	catch(std::exception & e){
		std::cout << "Exception cought " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "***Robotomy test***"<< std::endl;
	try{
		Bureaucrat a("James", 50);
		std::cout << a;
		RobotomyRequestForm f("Coal miners");
		std::cout << f;
		
		std::cout << std::endl;

		f.beSigned(a);
		std::cout << f;
		a.executeForm(f);
		std::cout << std::endl;
	}
	catch(std::exception & e){
		std::cout << "Exception cought " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "***Schrubbery test***"<< std::endl;
	try{
		Bureaucrat a("James", 130);
		std::cout << a;
		ShrubberyCreationForm f;
		std::cout << f;
		
		std::cout << std::endl;

		f.beSigned(a);
		std::cout << f;
		a.executeForm(f);
		std::cout << std::endl;
	}
	catch(std::exception & e){
		std::cout << "Exception cought " << e.what() << std::endl;
	}
	return 0;
}

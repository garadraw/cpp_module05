/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:59:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/15 18:40:59 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{


	std::cout << "First Test, grade 100" << std::endl;
	try
	{
		Bureaucrat a;
		std::cout << a;
		a.increment();
		std::cout << a;
		std::cout << std::endl;
		Bureaucrat b("Mitica_100", 100);
		std::cout << b;
		b.decrement();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception arisen :)) " << e.what() <<std::endl;
	}


	std::cout << std::endl;
	std::cout << "Second Test, grade 0" << std::endl;

	try
	{
		Bureaucrat a("Mitica_0", 0);
		std::cout << a;
		a.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << "ExceptionArisen" << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Third Test, grade 151" << std::endl;

	try
	{
		Bureaucrat a("Mitica_151", 151);
		std::cout << a;
		a.increment();
	}
	catch(std::exception &e)
	{
		std::cout << "Exception Arisen " << e.what() <<std::endl;
	}
	return (0);
}

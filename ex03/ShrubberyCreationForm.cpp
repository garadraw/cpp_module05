/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:28:54 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/16 15:02:27 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : 
	Form("Shrubbery Creation Form", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm() : 
	Form("Shrubbery Creation Form", 145, 137), _target("Lici"){
		
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm Deconstructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(), _target(obj._target){
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	std::cout << "ShrubberyCreationForm Overloader = Function Called" << std::endl;
	this->_target = obj.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &execute) const {
	if (this->getIfSigned() == false)
		throw Form::FormNotSigned();
	if (this->getReqExec() < execute.getGrade())
		throw Form::GradeLow();
	std::string name = this->getTarget() + "_shrubbery";
	std::ofstream outfile(name);
	outfile << "                     - - -" << std::endl;
	outfile << "                   -        -  -     --    -" << std::endl;
	outfile << "                -                 -         -  -" << std::endl;
	outfile << "                                -" << std::endl;
	outfile << "                               -                --" << std::endl;
	outfile << "               -          -            -              -" << std::endl;
	outfile << "               -            '-,        -               -" << std::endl;
	outfile << "               -              'b      *" << std::endl;
	outfile << "                -              '$    #-                --" << std::endl;
	outfile << "               -    -           $:   #:               -" << std::endl;
	outfile << "             --      -  --      *#  @):        -   - -" << std::endl;
	outfile << "                          -     :@,@):   ,-**:'   -" << std::endl;
	outfile << "              -      -,         :@@*: --**'      -   -" << std::endl;
	outfile << "                       '#o-    -:(@'-@*'  -" << std::endl;
	outfile << "               -  -       'bq,--:,@@*'   ,*      -  -" << std::endl;
	outfile << "                          ,p$q8,:@)'  -p*'      -" << std::endl;
	outfile << "                   -     '  - '@@Pp@@*'    -  -" << std::endl;
	outfile << "                   -  - --    Y7'.'     -  -" << std::endl;
	outfile << "                              :@):." << std::endl;
	outfile << "                             .:@:'." << std::endl;
	outfile << "                           .::(@:.      -Sam Blumenstein-" << std::endl;
	outfile.close();
}
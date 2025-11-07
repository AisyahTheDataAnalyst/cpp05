/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:33:07 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/07 10:48:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//1. OCF
ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


//2. getter

const std::string &ShrubberyCreationForm::getTarget() const { return this->_target; }


//3. action

void ShrubberyCreationForm::action() const
{
	std::cout << GREEN << "Creating a file " << this->_target << "_shrubbery for a moment...\n";
	
	std::string filename;
	filename = this->_target + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << filename << " failed to open.\n";
		return ; 
	}

	file
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠙⠛⠋⠙⠿⢿⡿⠿⠁⠀⠀⠀⠀⠀⠈⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠉⠙⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠙⠋⠀⠀⠂⠀⠀⠀⠀⠄⠀⠀⠀⠀⠤⠉⠛⠶⣄⣠⣤⣤⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⠟⠃⠀⠀⠀⢀⣀⠀⠀⠀⠀⣐⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⣽⡯⡭⠄⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀⠀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠠⠄⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠴⠆⠀⠀⠀⠀⠀⠀⠉⠈⠉⠀⠀⠀⠄⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⡿⠿⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠀⠀⠀⠁⠀⠀⠀⠀⠸⢿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠺⢿⣿⣿⣿\n"
	<<	"⣿⠿⠿⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿\n"
	<<	"⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹\n"
	<<	"⣆⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈\n"
	<<	"⣿⣿⣿⡆⣠⡤⠀⠆⡀⠀⣀⠓⠄⢴⡆⠀⠀⠀⠀⠀⠀⠀⢴⡀⠀⢦⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣾\n"
	<<	"⣿⣿⣿⣿⣿⣷⣶⣿⣿⣶⣿⣿⣷⣶⣤⣄⡀⢀⣤⣤⣴⣦⣄⡁⠀⠀⠀⡶⠀⢰⣿⣶⣴⣿⣿⣿⣦⠈⠁⠀⢀⣠⡀⠀⢀⣄⣀⢀⣠⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⡄⠀⠈⢀⣴⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣼⣿⣿⣷⣾⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	<<	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠁⠀⠀⠙⠻⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	<< std::endl;

	file.close();
	std::cout << this->_target << "_shrubbery file created!" << RESET << std::endl;
}


// 4. ostream << operator accepting ShrubberyCreationForm class

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &value)
{
	out << "Form name: " << value.getFormName() 
		<< ", target's name: " << value.getTarget() << "." << std::endl;
	return out;
}
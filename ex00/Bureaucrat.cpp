/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:10 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 17:47:02 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// OCF

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) 
{
	std::cout << CYAN << "Bureaucrat : Default constructor of " << this->_name << " called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << CYAN << "Bureaucrat : Parameterized constructor of " << this->_name << " called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name("Default_copy")
{
	std::cout << CYAN << "Bureaucrat : Copy constructor of " << this->_name << " called." << RESET << std::endl;
	*this = other;
}

// name is const, so we dont overwrite it
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << CYAN << "Bureaucrat : Copy assignment operator of " << this->_name << " called." << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << CYAN << "Bureaucrat : Destructor of " << this->_name << " called." << RESET << std::endl;
}

//---------------------------------------------------
// methods
// 1. getters

const std::string &Bureaucrat::getName() const { return this->_name; }

const int &Bureaucrat::getGrade() const { return this->_grade; }


// 2. grade adjustments

void Bureaucrat::incrementGrade()
{
	--this->_grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	++this->_grade;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


// 3. exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}


// 4. ostream << operator overload on Bureaucrat class

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << "." << '\n';
	return out;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:10 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:56:47 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// OCF

Bureaucrat::Bureaucrat()
: _name("Default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();	
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name("Default_copy")
{
	*this = other;
}

// name is const, so we dont overwrite it
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

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
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	++this->_grade;
	if (this->_grade > 150)
		throw GradeTooLowException();
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


// 4. action

// AForm parameter cannot be const coz we need to be change its _isItSigned
void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getFormName() << "." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << this->_name << " could not sign " << form.getFormName() << " because " << e.what() << "." << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getFormName() << "." << std::endl;
	}
	catch(const std::exception &errMsg)
	{
		std::cerr << RED << this->_name << " didn't executed " << form.getFormName() << " because of " << errMsg.what() << '\n' << RESET;
	}
}

// 5. ostream << operator overload for class Bureaucrat

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << "." << std::endl;
	return out;
}
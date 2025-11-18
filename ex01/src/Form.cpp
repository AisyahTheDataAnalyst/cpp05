/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:38:00 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:56:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// ------------------------------------------------
// OCF

// why cant i initialized them in the function body?
// => must initialize in the initializer list bcoz the attributes are consts/reference/dont have ctor
Form::Form()
: _formName("Miscellaneous Form"), _isItSigned(false), _gradeToSign(20), _gradeToExecute(10)
{}

Form::Form(std::string formName, int gradeToSign, int gradeToExecute)
: _formName(formName), _isItSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// need to initialize const attributes
Form::Form(const Form &other)
: _formName(other._formName), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	*this = other;
}

// not overwriting const attributes
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isItSigned = other._isItSigned;
	return *this;
}

Form::~Form() {}

// -------------------------------------------------------------------------
// methods
// 1. actions

void Form::beSigned(const Bureaucrat &person)
{
	if (person.getGrade() < 1)
		throw Form::GradeTooHighException();
	if (person.getGrade() > 150 || person.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	if (person.getGrade() <= this->_gradeToSign)
		this->_isItSigned = true;
}


// 2. exceptions

const char *Form::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade too low"; }


// 3. getters

const std::string &Form::getFormName() const { return this->_formName; }

const int &Form::getGradeToSign() const { return this->_gradeToSign; }

const int &Form::getGradeToExecute() const { return this->_gradeToExecute; }

const bool &Form::getIsItSigned() const { return this->_isItSigned; }


// 4. << operator overload on class Form

std::ostream &operator<<(std::ostream &out, const Form &value)
{
	out	<< CYAN
		<< "Form: [" << value.getFormName() << "]"
		<< ", sign grade: " << value.getGradeToSign()
		<< ", execute grade: " << value.getGradeToExecute()
		<< ", sign status: " << value.getIsItSigned()
		<< "." << RESET << std::endl;
	return out;
}

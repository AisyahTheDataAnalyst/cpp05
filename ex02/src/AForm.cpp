/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:30:14 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:56:27 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// ------------------------------------------------
// OCF

AForm::AForm()
: _formName("Miscellaneous AForm"), _isItSigned(false), _gradeToSign(20), _gradeToExecute(10)
{}

AForm::AForm(std::string formName, int gradeToSign, int gradeToExecute)
: _formName(formName), _isItSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

// need to initialize const attributes
// why cant i initialized them in the function body?
AForm::AForm(const AForm &other)
: _formName(other._formName), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	*this = other;
}

// not overwriting const attributes
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isItSigned = other._isItSigned;
	return *this;
}

AForm::~AForm() {}

// -------------------------------------------------------------------------
// methods
// 1. actions

void AForm::beSigned(const Bureaucrat &person)
{
	if (person.getGrade() < 1)
	throw GradeTooHighException();
	if (person.getGrade() > 150 || person.getGrade() > this->_gradeToSign)
	throw GradeTooLowException();
	if (person.getGrade() <= this->_gradeToSign)
	this->_isItSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() < 1)
		throw GradeTooHighException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsItSigned())
		throw std::runtime_error("not signed yet");
	action();
}


// 2. exceptions

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }


// 3. getters

const std::string &AForm::getFormName() const { return this->_formName; }

const int &AForm::getGradeToSign() const { return this->_gradeToSign; }

const int &AForm::getGradeToExecute() const { return this->_gradeToExecute; }

const bool &AForm::getIsItSigned() const { return this->_isItSigned; }


// 4. << operator overload on class AForm

std::ostream &operator<<(std::ostream &out, const AForm &value)
{
	out	<< "AForm: [" << value.getFormName() << "]"
		<< ", sign grade: " << value.getGradeToSign()
		<< ", execute grade: " << value.getGradeToExecute()
		<< ", sign status: " << value.getIsItSigned()
		<< "." << std::endl;
	return out;
}

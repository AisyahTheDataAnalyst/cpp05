/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:33:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:54:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//OCF
PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm("PresidentialPardonForm", 25, 5)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}


//2. getter

const std::string &PresidentialPardonForm::getTarget() const { return this->_target; }


//3. action

void PresidentialPardonForm::action() const
{
	std::cout << PURPLE << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}


// 4. ostream << operator accepting PresidentialPardonForm class

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &value)
{
	out << "Form name: " << value.getFormName() 
		<< ", target's name: " << value.getTarget() << "." << std::endl;
	return out;
}
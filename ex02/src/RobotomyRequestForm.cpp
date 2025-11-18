/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:33:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:54:38 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//OCF
RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm("RobotomyRequestForm", 72, 45)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


//2. getter

const std::string &RobotomyRequestForm::getTarget() const { return this->_target; }


//3. action

void RobotomyRequestForm::action() const
{
	std::cout << CYAN << "***some drilling sound***\n" << this->_target;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1)
		std::cout  << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << " robotomy has failed." << RESET << std::endl;
}


// 4. ostream << operator accepting RobotomyRequestForm class

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &value)
{
	out << "Form name: " << value.getFormName() 
		<< ", target's name: " << value.getTarget() << "." << std::endl;
	return out;
}
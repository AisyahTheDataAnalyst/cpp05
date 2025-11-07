/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:06:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/07 15:03:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//OCF
Intern::Intern() {}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}
		
Intern::Intern(const Intern &other)
{
	(void)other;
}
		
Intern::~Intern() {}


//method

AForm *Intern::makeForm(std::string form, std::string target) const
{
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	for (; i < 3; ++i)
		if (form == formNames[i])
			break ;

	enum formNum
	{
		ShrubberyCreationF,
		RobotomyRequestF,
		PresidentialPardonF,
	};

	switch (i)
	{
		case ShrubberyCreationF:
			std::cout << "Intern creates " << form << "." << std::endl;
			return new ShrubberyCreationForm(target);
		case RobotomyRequestF:
			std::cout << "Intern creates " << form << "." << std::endl;
			return new RobotomyRequestForm(target);
		case PresidentialPardonF:
			std::cout << "Intern creates " << form << "." << std::endl;;
			return new PresidentialPardonForm(target);
		default:
			std::cerr << "Form name is invalid.\n";
			return NULL;
	}
}

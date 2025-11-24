/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:38:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/24 09:47:48 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	border(std::string title, const char *colour)
{
	std::cout << colour << "\n============================================================\n";
	std::cout << title << "\n";
	std::cout << "============================================================" << RESET << std::endl;
}

int main()
{
	Intern me;
	AForm *form;

	form = me.makeForm("ShrubberyCreationForm", "HauntedHouse");
	delete form;
	form = me.makeForm("RobotomyRequestForm", "Sheldon Cooper");
	delete form;
	form = me.makeForm("ridicolous form", "witch");
	delete form;
	form = me.makeForm("PresidentialPardonForm", "cats");
	delete form;
}
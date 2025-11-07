/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:38:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/07 11:05:09 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
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
	try
	{
		border("Forms and Bureaucrats instances creation", YELLOW);
		
		// AForm a("Lawsuit", 1, 2); // abstract class
		// ShrubberyCreationForm fB1; // - privated
		// RobotomyRequestForm fR1; // -privated
		// PresidentialPardonForm fP1; // -privated 

		ShrubberyCreationForm fB("Kindergarten");
		std::cout << fB;
		RobotomyRequestForm fR("Pinocchio");
		std::cout << fR;
		PresidentialPardonForm fP("Leanord");
		std::cout << fP << '\n';

		Bureaucrat bA("Andy", 1);
		std::cout << bA;
		Bureaucrat bB("Bob", 15);
		std::cout << bB;
		Bureaucrat bC("Cindy", 60);
		std::cout << bC;
		Bureaucrat bD("Donald", 140);
	}
	catch (std::exception &errMsg)
	{
		std::cerr << errMsg.what() << '\n';
	}
	
	try
	{
		border("Test1: No exception thrown", BLUE);

		ShrubberyCreationForm fB("Treehouse");
		RobotomyRequestForm fR("Pinocchio");
		PresidentialPardonForm fP("Leanord");
		Bureaucrat bA("Andy", 1);
		Bureaucrat bB("Bob", 15);
		Bureaucrat bC("Cindy", 60);
		Bureaucrat bD("Donald", 140);

		bD.signForm(fB);
		bC.executeForm(fB);
		std::cout << '\n';
		bC.signForm(fR);
		bB.executeForm(fR);
		std::cout << '\n';
		bB.signForm(fP);
		bA.executeForm(fP);
		std::cout << "\nWill reach this text here" << std::endl;
	}
	catch(const std::exception& errMsg)
	{
		std::cerr << errMsg.what() << '\n';
	}
	
	try
	{
		border("Test2: Exceptions thrown", BLUE);

		ShrubberyCreationForm fB("Treehouse");
		RobotomyRequestForm fR("Pinocchio");
		PresidentialPardonForm fP("Leanord");
		Bureaucrat bA("Andy", 1);
		Bureaucrat bB("Bob", 15);
		Bureaucrat bC("Cindy", 60);
		Bureaucrat bD("Donald", 140);
		// Bureaucrat bE("Eleanor", 170); // grade too low
		// Bureaucrat bF("Fiona", -2); // grade too high

		// bD.signForm(fB);
		bC.executeForm(fB); // not signed
		std::cout << '\n';
		bC.signForm(fR);
		bD.executeForm(fR); // grade too low, should ask bB instead
		std::cout << '\n';
		bC.signForm(fP); // grade too low, should ask bB instead
		bA.executeForm(fP); // not signed yet
		std::cout << "\nWill reach this text here because signForm and executeForm has their own catch" << std::endl;
	}
	catch (std::exception &errMsg)
	{
		std::cerr << errMsg.what() << '\n';
	}
	return 0;
}
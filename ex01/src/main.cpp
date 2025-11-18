/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:38:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:06:54 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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
		Form a("Lawsuit", 1, 2);
		std::cout << a;
		Form b("Annual Dinner Budget", 5, 7);
		std::cout << b;
		Form c("Financial Statement", 10, 13);
		std::cout << c;
		Form d("Technical Workshop Plan", 50, 55);
		std::cout << d;
		Form e;
		std::cout << e;
		Form CC(a);
		std::cout << CC;
		Form CAO = CC;
		std::cout << CAO;
		// Form f("Random", 150, 170);
		// std::cout << f;
		// Form g("It wont reach here even though this is valid", 140, 145);
		// std::cout << g << '\n';
		
		Bureaucrat bA("Andy", 1);
		std::cout << bA;
		Bureaucrat bB("Bob", 5);
		std::cout << bB;
		Bureaucrat bC("Cindy", 10);
		std::cout << bC;
		Bureaucrat bD("Donald", 50);
		std::cout << bD;
		Bureaucrat bE;
		Bureaucrat bCC(bE);
		std::cout << bC;
		Bureaucrat bCAO(bCC);
		std::cout << bCAO;
		// Bureaucrat bF("Frozone", -1);
		// std::cout << bF;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	
	try
	{
		border("Test1: No exceptions", BLUE);
		Form a("Lawsuit", 1, 2);
		std::cout << a;
		Form c("Financial Statement", 10, 13);
		std::cout << c;
		Bureaucrat bA("Andy", 1);
		std::cout << bA;

		a.beSigned(bA);
		c.beSigned(bA);
		std::cout << "Will reach this text here" << std::endl;
		// or
		bA.signForm(a);
		bA.signForm(c);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	try
	{
		border("Test2: Executions thrown for beSigned", BLUE);
		Form b("Annual Dinner Budget", 5, 7);
		std::cout << b;
		Form d("Technical Workshop Plan", 50, 55);
		std::cout << d;
		Bureaucrat bB("Bob", 5);
		std::cout << bB;
		Bureaucrat bE;
		std::cout << bE;

		std::cout << "1: ";
		b.beSigned(bB);
		std::cout << GREEN << "ok!\n" << RESET << "2: "; 
		b.beSigned(bE); // exception here will caught by int main's catch. will stop here	
		std::cout << GREEN << "ok!\n" << RESET << "3: ";
		d.beSigned(bB);
		std::cout << GREEN << "ok!\n" << RESET << "4: ";
		d.beSigned(bE);	// exception here will caught by int main's catch. will stop here
		std::cout << GREEN << "ok!" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	try
	{
		border("Test3: Executions thrown for signForm", BLUE);
		Form b("Annual Dinner Budget", 5, 7);
		std::cout << b;
		Form d("Technical Workshop Plan", 50, 55);
		std::cout << d;
		Bureaucrat bB("Bob", 5);
		std::cout << bB;
		Bureaucrat bE;
		std::cout << bE;

		bB.signForm(b);
		bB.signForm(d);
		bE.signForm(b); // have exception but already been caught within this function
		bE.signForm(d); // have exception but already been caught within this function
		std::cout << "Will reach this text here" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	return 0;
}
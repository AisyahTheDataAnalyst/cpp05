/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/24 10:55:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		border("No exception thrown", BLUE);
		Bureaucrat a, b;
		Bureaucrat c("Kaichou", 2), d("Ass. Director", 3);
		std::cout << "Before grade adjustments:" << std::endl;
		std::cout << a << b << c << d << std::endl;
		std::cout << "After grade adjustments:\n";
		a.incrementGrade();
		b.incrementGrade();
		c.decrementGrade();
		d.decrementGrade();
		std::cout << a << b << c << d << std::endl;
		std::cout << "Will reach this text here" << std::endl;
	}
	catch (const std::exception &errMsg)
	{
		std::cerr << RED << errMsg.what() << '\n' << RESET;
	}

	try
	{
		border("Exceptions thrown after grade increment (too high)", BLUE);
		Bureaucrat a("Kaichou", 1);
		std::cout << "Before grade increment:\n";
		std::cout << a;
		std::cout << "After grade increment:" << std::endl;
		a.incrementGrade();
		std::cout << a;
		std::cout << "Won't reach this text here" << std::endl;
	}
	catch ( const Bureaucrat::GradeTooHighException errMsg) // or // catch ( const Bureaucrat::GradeTooHighException &errMsg)
	{
		std::cerr << RED << "Caught nested exception: " << errMsg.what() << '\n' << RESET;
	}
	catch (const std::exception &errMsg)
	{
		std::cerr << RED << "Caught exception in general: " << errMsg.what() << '\n' << RESET;
	}

	try
	{
		border("Exceptions thrown after grade decrement (too low)", BLUE);
		Bureaucrat a;
		std::cout << "Before grade decrement:\n";
		std::cout << a;
		std::cout << "After grade decrement:\n";
		a.decrementGrade();
		std::cout << a;
		std::cout << "Won't reach this text here" << std::endl;
	}
	catch ( const Bureaucrat::GradeTooLowException errMsg) // or // catch ( const Bureaucrat::GradeTooLowException &errMsg)
	{
		std::cerr << RED << "Caught nested exception: " << errMsg.what() << '\n' << RESET;
	}
	catch (const std::exception &errMsg)
	{
		std::cerr << RED << "Caught exception in general: " << errMsg.what() << '\n' << RESET;
	}

	try
	{
		border("Exceptions thrown upon instances creation (grade too high)", BLUE);
		Bureaucrat a("Kaichou", 0);
		std::cout << "Wont reach this text here" << std::endl;
	}
	catch (const std::exception &errMsg)
	{
		std::cerr << RED << errMsg.what() << '\n' << RESET;
	}

	try
	{
		border("Exceptions thrown upon instances creation (grade too low)", BLUE);
		Bureaucrat a("Andy", 170);
		std::cout << "Wont reach this text here" << std::endl;
	}
	catch (const std::exception &errMsg)
	{
		std::cerr << RED << errMsg.what() << '\n' << RESET;
	}

	return 0;
}
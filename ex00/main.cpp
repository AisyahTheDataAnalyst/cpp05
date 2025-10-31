/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/10/31 09:10:50 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	border(std::string title)
{
	std::cout << BLUE << "\n============================================================\n";
	std::cout << title << "\n";
	std::cout << "============================================================" << RESET << std::endl;
}

int main()
{
	{
		try
		{
			border("No exception thrown");
			Bureaucrat a, b;
			Bureaucrat c("Kaichou", 2), d("Ass. Director", 3);
			std::cout << "Before grade adjustments:" << std::endl;
			std::cout << a << b << c << d << std::endl;
			std::cout << "After grade adjustments:\n";
			a.incrementGrade();
			b.incrementGrade();
			c.decrementGrade();
			d.decrementGrade();
			std::cout << a << b << c << d;
			std::cout << "Will reach here" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			border("Exceptions thrown after grade increment (too high)");
			Bureaucrat a("Kaichou", 1);
			std::cout << "Before grade increment:\n";
			std::cout << a;
			std::cout << "After grade increment:\n";
			a.incrementGrade();
			std::cout << a;
			std::cout << "Won't reach here" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			border("Exceptions thrown after grade decrement (too low)");
			Bureaucrat a;
			std::cout << "Before grade decrement:\n";
			std::cout << a;
			std::cout << "After grade decrement:\n";
			a.decrementGrade();
			std::cout << a;
			std::cout << "Won't reach here" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			border("Exceptions thrown upon instances creation (grade too high)");
			Bureaucrat a("Kaichou", 0);
			std::cout << "Wont reach here" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			border("Exceptions thrown upon instances creation (grade too low)");
			Bureaucrat a("Andy", 170);
			std::cout << "Wont reach here" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
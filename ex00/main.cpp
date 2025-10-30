/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/10/30 19:50:39 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	border(std::string title)
{
	std::cout << "=======================================================\n";
	std::cout << title << "\n";
	std::cout << "=======================================================" << std::endl;
}

int main()
{
	{
		border("No any exceptions thrown");
		Bureaucrat a, b;
		Bureaucrat c("Kaichou", 2), d("Ass. Director", 3);
		
		try
		{
			std::cout << "Before grade adjustments:" << std::endl;
			std::cout << a << b << c << d << std::endl;
			std::cout << "After grade adjustments:\n";
			a.incrementGrade();
			b.incrementGrade();
			c.decrementGrade();
			d.decrementGrade();
			std::cout << a << b << c << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
			{
		border("No any exceptions thrown");
		Bureaucrat a, b;
		Bureaucrat c("Kaichou", 2), d("Ass. Director", 3);
		
		try
		{
			std::cout << "Before grade adjustments:\n";
			std::cout << a << b << c << d << std::endl;
			std::cout << "After grade adjustments:\n";
			a.incrementGrade();
			b.incrementGrade();
			c.decrementGrade();
			d.decrementGrade();
			std::cout << a << b << c << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	}
}
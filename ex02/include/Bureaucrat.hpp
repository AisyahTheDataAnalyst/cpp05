/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:07 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 18:55:34 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define RED	"\033[1;31m"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		//OCF
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		//methods
		const std::string &getName() const;
		const int &getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;
		void executeForm(const AForm &form);

		//exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);

#endif
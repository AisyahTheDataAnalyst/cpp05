/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:07 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/18 17:47:18 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define CYAN	"\033[1;36m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		//OCF
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		//methods
		const std::string &getName() const;
		const int &getGrade() const;
		void incrementGrade();
		void decrementGrade();

		// exception classes
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
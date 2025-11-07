/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:30:25 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/07 10:41:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_formName;
		bool				_isItSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// OCF
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		//methods
		const std::string &getFormName() const;
		const bool &getIsItSigned() const;
		const int &getGradeToSign() const;
		const int &getGradeToExecute() const;
		void beSigned(const Bureaucrat &pic);
		void execute(Bureaucrat const &executor) const;

		//virtual/pure virtual fn
		virtual void action() const = 0;

		//exception classes
		class GradeTooHighException: public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &value);

#endif